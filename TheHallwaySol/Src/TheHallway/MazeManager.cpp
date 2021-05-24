#include "MazeManager.h"
#include "Rigidbody.h"
#include "MeshRenderer.h"
#include "QuackEntity.h"
#include "SceneMng.h"
#include "Lever.h"
#include "Exit.h"
#include "MazeRunner.h"

MazeManager::MazeManager()
{
}

bool MazeManager::init(luabridge::LuaRef parameterTable)
{
	// para el laberinto
	readVariable<int>(parameterTable, "Size", &size_);
	readVariable<size_t>(parameterTable, "Holes", &additionalPaths_);
	
	// para los enemigos
	readVariable<int>(parameterTable, "Ghosts", &numGhosts_);
	readVariable<int>(parameterTable, "Enemies", &numEnemies_);
	readVariable<float>(parameterTable, "GhostRadar", &ghostRadar_);
	readVariable<float>(parameterTable, "EnemyRadar", &enemyRadar_);
	readVariable<int>(parameterTable, "PointsGhosts", &pointsGhost_);

	// para las palancas
	readVariable<size_t>(parameterTable, "Levers", &numLevers_);
	readVariable<float>(parameterTable, "ChargeVel", &chargeVel_);
	readVariable<float>(parameterTable, "UnchargeVel", &unchargeVel_);
	
	invalidDir_ = Vector2(-size_, -size_);
	visitedCells_ = std::vector <std::vector<bool>>(size_, std::vector<bool>(size_, false));
	map_ = std::vector<std::vector<char>>(size_ * 2 + 1, std::vector<char>(size_ * 2 + 1, wallC_));
	return true;
}

void MazeManager::start()
{
	createMaze();
}

void MazeManager::createMaze()
{
	huntAndKill();				// algoritmo de hunt n kill
	spawnPlayer();				// spawneamos el jugador
	createInteractables();		// metemos las palancas
	eraseColumns();				// borramos las columnas que hayan podido quedar
	writeMap();					// lo guardamos en el archivo
}

void MazeManager::kill(Vector2 pos)
{
	VisitCell(pos);
	setCell(floorC_, getArrayVector(pos));

	// escogemos una direccion al azar
	int i = rand() % DIRECTIONS.size();

	Vector2 nextCell;

	// buscamos una direccion valida
	int loops = 0;

	do
	{
		nextCell.first = pos.first + DIRECTIONS[(i + loops) % DIRECTIONS.size()].first;
		nextCell.second = pos.second + DIRECTIONS[(i + loops) % DIRECTIONS.size()].second;
		loops++;

	} while (loops < DIRECTIONS.size() && (!validDir(nextCell) || visitedCells_[nextCell.first][nextCell.second]));

	if (validDir(nextCell) && !visitedCells_[nextCell.first][nextCell.second])
	{
		// tiramos la pared entre la celda actual y la vecina que hemos escogido
		knockDownWall(pos, nextCell);

		kill(nextCell);
	}
}

Vector2 MazeManager::hunt()
{
	Vector2 huntedCell = invalidDir_;
	std::vector<Vector2> neighbours = std::vector<Vector2>();

	// buscamos una celda sin visitar con una vecina visitada
	int i = 0, j;
				
	while (i < visitedCells_.size() && neighbours.empty())
	{
		j = 0;
		while (j < visitedCells_[i].size() && neighbours.empty())
		{
			if (!visitedCells_[i][j])
			{
				huntedCell = Vector2(i, j);
				for (int k = 0; k < DIRECTIONS.size(); k++)
				{
					// si se ha visitado, se anade a la lista
					Vector2 possibleConnection;
					possibleConnection.first = huntedCell.first + DIRECTIONS[k].first;
					possibleConnection.second = huntedCell.second + DIRECTIONS[k].second;

					if (validDir(possibleConnection) && visitedCells_[possibleConnection.first][possibleConnection.second])
						neighbours.push_back(possibleConnection);
				}

			}
			j++;
		}
		i++;
	}

	// escogemos una vecina al azar
	if (neighbours.size() > 0)
	{
		Vector2 cell = (neighbours.at(rand() % neighbours.size()));
		knockDownWall(huntedCell, cell);

		VisitCell(huntedCell);
	}

	return huntedCell;
}

bool MazeManager::knockDownWall(Vector2 hunted, Vector2 other)
{
	//direccion (hunted POV)
	Vector2 direccion;
	direccion.first = other.first - hunted.first;
	direccion.second = other.second - hunted.second;
	hunted = getArrayVector(hunted);

	hunted.first += direccion.first;
	hunted.second += direccion.second;

	// si ya se ha derribado, no se puede volver a tirar
	if (map_[hunted.first][hunted.second] != wallC_)
		return false;

	setCell(floorC_, hunted);
	return true;
}

void MazeManager::huntAndKill()
{
	// empezamos en un punto aleatorio
	size_t x = rand() % size_, y = rand() % size_;
	Vector2 cell = Vector2(x, y);
	VisitCell(cell);

	do
	{
		kill(cell);
	} while ((cell = hunt()) != invalidDir_);

	createGaps();
}

void MazeManager::createGaps()
{
	int tries = 0;
	while (additionalPaths_ > 0)
	{
		Vector2 cell = Vector2(rand() % size_, rand() % size_);
		Vector2 other;
		other.first = cell.first + DIRECTIONS[rand() % DIRECTIONS.size()].first;
		other.second = cell.second + DIRECTIONS[rand() % DIRECTIONS.size()].second;

		// si se tira la pared, hay un additionalpath menos que crear
		// hay un numero de intentos definido (3) para tirar una pared: si no, esto podria ser un bucle infinito
		if (validDir(other) && knockDownWall(cell, other) || tries == 3)
		{
			additionalPaths_--;
			tries = 0;
		}
		// si no se puede tirar la pared, se le da otro intento
		else
			tries++;
	}
}

void MazeManager::createInteractables()
{
	int i = 0, tries = 0;
	// creamos las manivelas necesarias
	while (i < numLevers_)
	{
		Vector2 cell = Vector2(rand() % size_, rand() % size_);

		// si se tira la pared, hay un additionalpath menos que crear
		// hay un numero de intentos definido (3) para tirar una pared: si no, esto podria ser un bucle infinito
		if (validDir(cell))
		{
			cell = getArrayVector(cell);
			if (map_[cell.first][cell.second] != leverC_ && map_[cell.first][cell.second] != playerC_)
			{
				setCell(leverC_, cell);
				i++; tries = 0;
			}
		}
		// si no se puede tirar la pared, se le da otro intento
		else
		{
			assert(tries < size_* size_);
			tries++;			
		}
	}

	bool door = false;
	// creamos una puerta
	exit_ = getRandomFloor();
}

void MazeManager::writeMap()
{
	std::vector<std::vector<bool>> mapaAuxiliar(size_*2+1, std::vector<bool>(size_ * 2 + 1, true));
	// creamos los bordes como un solo cubo para ahorrar please
	createOuterWalls();

	// para pruebas solo
	std::string path = "C:\\Users\\anaana\\Desktop\\Maps\\mapa.map";
	std::ofstream f;
	f.open(path);
	for (int i = 0; i < 2 * size_ + 1; i++)
	{
		for (int j = 0; j < 2 * size_ + 1; j++)
		{
			f << map_[i][j];
		}
		f << "\n";
	}
	f.close();
	//TODO meter datos sobre el jugador, enemigos, lo necesario, antes de dibujar el mapa
	//		QuackEntity* qe = new QuackEntity("Nombre", active, "TAG");

	for (int i = 1; i < 2 * size_; i++)
	{
		int j = 1;
		while (j < 2 * size_)
		{
			// si es pared, intentamos optimizar, juntandola con otras paredes adyacentes
			if (map_[i][j] == wallC_ && mapaAuxiliar[i][j])
			{
				int hor = 1, ver = 1;
				int horInd = j + 1, verInd = i + 1;

				//comprobamos si el muro es m�s largo en horizontal o vertical
				while (horInd < 2 * size_ && map_[i][horInd] == wallC_ && mapaAuxiliar[i][horInd])
				{
					horInd++; hor++;
				}
				while (verInd < 2 * size_ && map_[verInd][j] == wallC_ && mapaAuxiliar[verInd][j])
				{
					verInd++; ver++;
				}
				bool horizontal = hor >= ver;
				int numBloquesPared = horizontal ? hor : ver;
				if (horizontal)
				{
					//quitamos las paredes, para que no se instancien varias veces
					for (int k = j; k < horInd; k++)
						mapaAuxiliar[i][k] = false;

					// creamos la pared con la escala y posicion correctas
					float pos = (j + (numBloquesPared - 1) * 0.5) * WALL_SCALE;
					QuackEntity* pared = createObject("Pared", Vector3D(pos, 0, i * WALL_SCALE),
						Vector3D(WALL_SCALE * numBloquesPared, WALL_SCALE, WALL_SCALE));
					j = horInd - 1;
				}
				else
				{
					//quitamos las paredes, para que no se instancien varias veces
					for (int k = i; k < verInd; k++)
						mapaAuxiliar[k][j] = false;

					// creamos la pared con la escala y posicion correctas
					float pos = (i + (numBloquesPared - 1) * 0.5) * WALL_SCALE;
					QuackEntity* pared = createObject("Pared", Vector3D(j * WALL_SCALE, 0, pos),
						Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE * numBloquesPared));
				}
			}

			// si es una manivela, la creamos 
			else if (map_[i][j] == leverC_)
			{
				QuackEntity* boton = createObject("Manivela", Vector3D(j * WALL_SCALE, 0, i * WALL_SCALE), Vector3D(100, 100, 100), "CuboPrueba.mesh", true);
				(boton->addComponent<Lever>())->setMazeMng(this);
				boton->getComponent<Lever>()->setChargingVel(chargeVel_);
				boton->getComponent<Lever>()->setUnchargingVel(unchargeVel_);
				(boton->addComponent<MazeRunner>())->getPlayer();
				boton->getComponent<MazeRunner>()->setManager(this);
				boton->getComponent<MazeRunner>()->setFloorChar(floorC_);
			}

			else if (map_[i][j] == playerC_)
			{
				assert(SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player"));
				SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player")->transform()->setGlobalPosition(Vector3D(j * WALL_SCALE, 1, i * WALL_SCALE));
			}

			// limpiamos el mapa para dejar solo marcas de suelo o pared
			if (map_[i][j] != wallC_)
				map_[i][j] = floorC_;
			j++;
		}
	}	
	path = "C:\\Users\\anaana\\Desktop\\Maps\\mapaDespues.map";
	f.open(path);
	for (int i = 0; i < 2 * size_ + 1; i++)
	{
		for (int j = 0; j < 2 * size_ + 1; j++)
		{
			f << map_[i][j];
		}
		f << "\n";
	}
	f.close();
}

void MazeManager::eraseColumns()
{
	int loops;
	bool wall;
	Vector2 dir, other;

	for (int i = 1; i < 2 * size_; i++)
	{
		for (int j = 1; j < 2 * size_; j++)
		{
			wall = false; loops = 0;
			dir = Vector2(i, j);

			// si hay pared al lado de una "columna" no es columna
			while (loops < DIRECTIONS.size() && !wall)
			{
				if (map_[dir.first][dir.second] == wallC_)
				{
					other.first = dir.first + DIRECTIONS[loops].first;
					other.second = dir.second + DIRECTIONS[loops].second;

					if (map_[other.first][other.second] == wallC_)
						wall = true;
				}
				loops++;
			}

			// si es columna, pasa a ser suelo
			if (!wall && map_[dir.first][dir.second] == wallC_)
				map_[dir.first][dir.second] = floorC_;
		}
	}
}

void MazeManager::spawnPlayer()
{
	int corner = rand() % 3;
	Vector2 cell = Vector2(1, 1);
	switch (corner)
	{
	case 0:
		cell = Vector2(2 * size_ - 1, 1);
		break;
	case 1:
		cell = Vector2(2 * size_ - 1, 2 * size_ - 1);
		break;
	case 2:
		cell = Vector2(1, 2 * size_ - 1);
		break;
	default:
		break;
	}

	setCell(playerC_, cell);
}

QuackEntity* MazeManager::createObject(std::string tag, Vector3D pos, Vector3D scale, std::string name, bool trig, Vector3D rot)
{
	QuackEntity* object = new QuackEntity(tag);
	MeshRenderer* r = object->addComponent<MeshRenderer>();

	if (name == "PT_PLANE") r->setMeshByPrefab(PrefabType::PT_PLANE);
	else if (name == "PT_CUBE") r->setMeshByPrefab(PrefabType::PT_CUBE);
	else r->setMeshByName(name);
	object->transform()->setGlobalPosition(pos);
	object->transform()->Scale(scale);
	object->transform()->setGlobalRotation(rot);

	Rigidbody* rb = object->addComponent<Rigidbody>();
	rb->setRigidbody(1, ColliderType::CT_BOX, trig, true);

	SceneMng::Instance()->getCurrentScene()->addEntity(object);
	return object;
}

void MazeManager::createOuterWalls()
{
	// horizontales
	QuackEntity* pared = createObject("Pared", Vector3D(WALL_SCALE * size_, 0, 0), Vector3D(WALL_SCALE * (size_ * 2 + 1), WALL_SCALE, WALL_SCALE));
	QuackEntity* pared2 = createObject("Pared", Vector3D(WALL_SCALE * size_, 0, WALL_SCALE * (size_ * 2)), Vector3D(WALL_SCALE * (size_ * 2 + 1), WALL_SCALE, WALL_SCALE));

	// verticales
	QuackEntity* pared3 = createObject("Pared", Vector3D(0, 0, WALL_SCALE * size_), Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE * (size_ * 2 - 1)));
	QuackEntity* pared4 = createObject("Pared", Vector3D(WALL_SCALE * (size_ * 2), 0, WALL_SCALE * size_), Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE * (size_ * 2 - 1)));

	// creamos el suelo
	QuackEntity* floor = createObject("Suelo", Vector3D(size_ * WALL_SCALE, 0, size_ * WALL_SCALE),
										Vector3D(size_ * WALL_SCALE, size_ * WALL_SCALE, 1), "PT_PLANE", false, Vector3D(-90, 0, 0));
	floor->getComponent<MeshRenderer>()->setMaterial("CuboDebug");
}

Vector2 MazeManager::getArrayVector(Vector2 pos)
{
	Vector2 realPos = pos;
	realPos.first *= 2; realPos.second *= 2;
	realPos.first += 1; realPos.second += 1;

	return realPos;
}

void MazeManager::activateLever()
{
	if (--numLevers_ <= 0)
	{
		//creamos una puerta
		QuackEntity* salida = createObject("Salida", Vector3D(exit_.first * WALL_SCALE, 0, exit_.second * WALL_SCALE), Vector3D(100, 100, 100), "CuboPrueba.mesh", true, Vector3D(180, 0, 0));
		salida->addComponent<Exit>();

	}
}

Vector2 MazeManager::getPositionInMap(Vector3D pos)
{
	// nos interesa la posicion en x, z
	// z es la fila, x la columna
	// pos[z][x]
	std::pair<float, float> aux = std::pair<float, float>(pos.z, pos.x);
	aux.first /= WALL_SCALE; aux.second /= WALL_SCALE;
	Vector2 ret = aux;

	if (aux.first - ret.first > 0.5) ret.first++;
	if (aux.second - ret.second > 0.5) ret.second++;
	return ret;
}

Vector3D MazeManager::getPositionInWorld(Vector2 pos, float y)
{
	Vector3D worldPos = Vector3D(pos.first, y, pos.second);
	worldPos *= WALL_SCALE;
	return worldPos;
}

Vector2 MazeManager::getRandomFloor()
{
	Vector2 pos;
	bool found = false;
	while (!found)
	{
		Vector2 cell = Vector2(rand() % size_, rand() % size_);
		if (validDir(cell))
		{
			cell = getArrayVector(cell);
			if (map_[cell.first][cell.second] == floorC_)
			{
				pos = cell;
				found = true;
			}
		}
	}
	return pos;
}
