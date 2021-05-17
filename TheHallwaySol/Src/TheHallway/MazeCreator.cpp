#include "MazeCreator.h"
#include "Rigidbody.h"
#include "MeshRenderer.h"
//#include "Transform.h"
#include "QuackEntity.h"
#include "SceneMng.h"


MazeCreator::MazeCreator()
{
}

bool MazeCreator::init(luabridge::LuaRef parameterTable)
{
	invalidDir_ = Vector2(-height_, -width_);
	visitedCells_ = std::vector <std::vector<bool>>(height_, std::vector<bool>(width_, false));
	map_ = std::vector<std::vector<char>>(height_ * 2 + 1, std::vector<char>(width_ * 2 + 1, wallC_));
	return true;
}

void MazeCreator::start()
{
	createMaze(filename);
}

void MazeCreator::createMaze(std::string filename)
{
	huntAndKill();      // algoritmo de hunt n kill

	eraseColumns();     // borramos las columnas que hayan podido quedar
	spawnPlayer();      // spawneamos el jugador

	writeMap(filename); // lo guardamos en el archivo
}

void MazeCreator::kill(Vector2 pos)
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

Vector2 MazeCreator::hunt()
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

bool MazeCreator::knockDownWall(Vector2 hunted, Vector2 other)
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

void MazeCreator::huntAndKill()
{
	// empezamos en un punto aleatorio
	size_t x = rand() % height_, y = rand() % width_;
	Vector2 cell = Vector2(x, y);
	VisitCell(cell);

	do
	{
		kill(cell);
	} while ((cell = hunt()) != invalidDir_);

	//createGaps();
}

void MazeCreator::createGaps()
{
	int tries = 0;
	while (additionalPaths_ > 0)
	{
		Vector2 cell = Vector2(rand() % height_, rand() % width_);
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

void MazeCreator::writeMap(std::string file)
{
	// creamos los bordes como un solo cubo para ahorrar please
	createOuterWalls();

	// para pruebas solo
	std::string path = "C:\\Users\\anaana\\Desktop\\Maps\\CPP.map";
	std::ofstream f;
	f.open(path);
	for (int i = 0; i < 2 * height_ + 1; i++)
	{
		for (int j = 0; j < 2 * width_ + 1; j++)
		{
			f << map_[i][j];
		}
		f << "\n";
	}
	f.close();
	//TODO meter datos sobre el jugador, enemigos, numero de palancas.. lo necesario, antes de dibujar el mapa
	for (int i = 1; i < 2 * height_; i++)
	{
		int j = 1;
		while(j < 2 * width_)
		{
			//Para optimizar la creación de muros, si el muro es de tamaño >1 en la x o la z, alargaremos su escala
			int hor = 0, ver = 0;
			int horInd = j + 1, verInd = i + 1;

			if (map_[i][j] == wallC_)
			{
				//comprobamos si el muro es más largo en horizontal o vertical
				while (horInd < 2 * width_ && map_[i][horInd] == wallC_)
				{
					horInd++; hor++;
				}
				while (verInd < 2 * width_ && map_[verInd][j] == wallC_)
				{
					verInd++; ver++;
				}
				bool horizontal = hor >= ver;
				int numBloquesPared = horizontal ? hor : ver; numBloquesPared++;
				QuackEntity* pared = createPared();
				if (horizontal)
				{
					//quitamos las paredes, para que no se instancien varias veces
					for (int k = j; k < horInd; k++)
						map_[i][k] = floorC_;

					// creamos la pared con la escala y posicion correctas
					float pos = (j + numBloquesPared * 0.5) * WALL_SCALE;
					pared->transform()->setGlobalPosition(Vector3D(pos, 0, i * WALL_SCALE));
					pared->transform()->Scale(Vector3D(WALL_SCALE * numBloquesPared, WALL_SCALE, WALL_SCALE));
					j = horInd;
				}
				else
				{
					//quitamos las paredes, para que no se instancien varias veces
					for (int k = i; k < verInd; k++)
						map_[k][j] = floorC_;

					// creamos la pared con la escala y posicion correctas
					float pos = (i + numBloquesPared * 0.5) * WALL_SCALE;
					pared->transform()->setGlobalPosition(Vector3D(j * WALL_SCALE, 0, pos));
					pared->transform()->Scale(Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE * numBloquesPared));
				}
			}
			else
				j++;
			//	//instaciamos el jugador
			//else if(map[i][j] == enemy1)
			//	//instanciamos el enemigo de tipo 1
			//else if(map[i][j] == enemy1)
			//	//instanciamos el enemigo de tipo 1
			
		}
	}
}

void MazeCreator::eraseColumns()
{
	int loops;
	bool wall;
	Vector2 dir, other;

	for (int i = 1; i < 2 * height_; i++)
	{
		for (int j = 1; j < 2 * width_; j++)
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
			if (!wall)
				map_[dir.first][dir.second] = floorC_;
		}
	}
}

QuackEntity* MazeCreator::createPared()
{
	QuackEntity* cube = new QuackEntity();
	MeshRenderer* r = cube->addComponent<MeshRenderer>();
	r->setMeshByPrefab(PrefabType::PT_CUBE); 
	Rigidbody* rb = cube->addComponent<Rigidbody>();
	rb->setRigidbody(1, ColliderType::CT_BOX, false, true);

	SceneMng::Instance()->getCurrentScene()->addEntity(cube);
	return cube;
}

void MazeCreator::createOuterWalls()
{

	QuackEntity* pared = createPared();
	pared->transform()->setGlobalPosition(Vector3D(WALL_SCALE * width_, 0, 0));
	pared->transform()->Scale(Vector3D(WALL_SCALE * (width_ * 2 + 1), WALL_SCALE, WALL_SCALE));

	QuackEntity* pared2 = createPared();
	pared2->transform()->setGlobalPosition(Vector3D(WALL_SCALE * width_, 0, WALL_SCALE * (height_ * 2)));
	pared2->transform()->Scale(Vector3D(WALL_SCALE * (width_ * 2 + 1), WALL_SCALE, WALL_SCALE));

	QuackEntity* pared3 = createPared();
	pared3->transform()->setGlobalPosition(Vector3D(0, 0, WALL_SCALE * height_));
	pared3->transform()->Scale(Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE * (height_ * 2 - 1)));

	QuackEntity* pared4 = createPared();
	pared4->transform()->setGlobalPosition(Vector3D(WALL_SCALE * (width_ * 2), 0, WALL_SCALE * height_));
	pared4->transform()->Scale(Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE * (height_ * 2 - 1)));
}


Vector2 MazeCreator::getArrayVector(Vector2 pos)
{
	Vector2 realPos = pos;
	realPos.first *= 2; realPos.second *= 2;
	realPos.first += 1; realPos.second += 1;

	return realPos;
}
