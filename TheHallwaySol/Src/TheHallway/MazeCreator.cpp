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
	while (additionalPaths_ > 0)
	{
		Vector2 cell = Vector2(rand() % height_, rand() % width_);
		Vector2 other;
		other.first = cell.first + DIRECTIONS[rand() % DIRECTIONS.size()].first;
		other.second = cell.second + DIRECTIONS[rand() % DIRECTIONS.size()].second;

		// if the wall can be knocked down, there is one less additional path to create
		if (validDir(other) && knockDownWall(cell, other))
			additionalPaths_--;
	}
}

void MazeCreator::writeMap(std::string file)
{
	//// para pruebas solo
	//std::string path = "C:\\Users\\anaana\\Desktop\\Maps\\CPP.map";
	//std::ofstream f;
	//f.open(path);
	//int n = height_ * 2 + 1;
	////f << n << "\n";           // altura para leerlo despues
	//n = width_ * 2 + 1;
	////f << n << "\n"; 
	
	//TODO meter datos sobre el jugador, enemigos, numero de palancas.. lo necesario, antes de dibujar el mapa
	for (int i = 0; i < 2 * height_ + 1; i++)
	{
		for (int j = 0; j < 2 * width_ + 1; j++)
		{
			//f << map_[i][j];
			if (map_[i][j] == wallC_)
			{
				//QuackEntity* pared = createPared();
				//pared->transform()->setGlobalPosition(Vector3D(i * WALL_SCALE, 0, j * WALL_SCALE));
				//pared->transform()->Scale(Vector3D(WALL_SCALE, WALL_SCALE, WALL_SCALE));
			}
				//crear una entidad dentro de la escena
			else if (map_[i][j] == playerC_)
			{

			}
			//	//instaciamos el jugador
			//else if(map[i][j] == enemy1)
			//	//instanciamos el enemigo de tipo 1
			//else if(map[i][j] == enemy1)
			//	//instanciamos el enemigo de tipo 1
				
		}
		//f << "\n";
	}
	//f.close();
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


Vector2 MazeCreator::getArrayVector(Vector2 pos)
{
	Vector2 realPos = pos;
	realPos.first *= 2; realPos.second *= 2;
	realPos.first += 1; realPos.second += 1;

	return realPos;
}
