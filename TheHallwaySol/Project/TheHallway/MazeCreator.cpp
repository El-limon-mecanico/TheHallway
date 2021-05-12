#include "MazeCreator.h"

void MazeCreator::createMaze(std::string filename)
{
	// creation from scratch
	if (squareMaze_) height_ = width_;
	//visitedCells_ = std::vector<Vector2>();
	//unvisitedCells_ = std::vector<Vector2>();
	invalidDir_ = Vector2(-height_, -width_);
	map_ = std::vector<std::string>(height_ * 2 + 1);

	// we set the whole maze as walls
	// the walls will be knocked down as the maze is calculated
	for (int i = 0; i < 2 * height_ + 1; i++)
	{
		for (int j = 0; j < 2 * width_ + 1; j++)
			setCell(wallC_, Vector2(i, j));
	}

	// no cell is visited
	for (int i = 0; i < height_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			visitedCells_[i][j] = false;
			//unvisitedCells_.push_back(Vector2(i, j));
		}
	}

	huntAndKill();      // algorithm for creating the maze

	eraseColumns();     // after creating additional paths, the columns are erased.
	spawnPlayer();      // the player is spawned in the bottom-left corner

	writeMap(filename); // save the file in a filename.map file
}

void MazeCreator::kill(Vector2 pos)
{
	VisitCell(pos);
	setCell(floorC_, getRealVector(pos));

	// escogemos una direccion al azar
	int i = rand() % DIRECTIONS.size();

	Vector2 nextCell;

	// check whether the path can be expanded in any direction from here
	int loops = 0;

	do
	{
		nextCell.first = pos.first + DIRECTIONS[(i + loops) % DIRECTIONS.size()].first;
		nextCell.second = pos.second + DIRECTIONS[(i + loops) % DIRECTIONS.size()].second;
		loops++;

	} while (loops < DIRECTIONS.size() && visitedCells_[nextCell.first][nextCell.second]);

	// if all the neighbour cells have already been visited, the kill process ends here.
	if (validDir(nextCell) && !visitedCells_[nextCell.first][nextCell.second])
	{
		// the wall between the actual position and the neighbour is knocked down
		// the path keeps expanding from this position
		knockDownWall(pos, nextCell);

		kill(nextCell);
	}
}

Vector2 MazeCreator::hunt()
{
	Vector2 huntedCell = invalidDir_;
	std::vector<Vector2> neighbours = std::vector<Vector2>();
	// search for the first unvisited cell with a visited neighbour cell
	int i = 0, j;
				//unvisited
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
					// if the cell has been visited, it is added to the neighbours list
					Vector2 possibleConnection;
					possibleConnection.first = huntedCell.first + DIRECTIONS[k].first;
					possibleConnection.second = huntedCell.second + DIRECTIONS[k].second;

					if (visitedCells_[possibleConnection.first][possibleConnection.second])
						neighbours.push_back(possibleConnection);
				}

			}

		}
		i++;
	}

	// a random neighbour is used
	if (neighbours.size() > 0)
	{
		Vector2 cell = (neighbours.at(rand() % neighbours.size()));
		knockDownWall(huntedCell, cell);

		// the "hunted" cell is visited
		VisitCell(huntedCell);
	}

	// returns an invalid direction if the list of unvisited cells had 0 elements
	return huntedCell;
}

void MazeCreator::huntAndKill()
{
	// we start at a random position
	size_t x = rand() % height_, y = rand() % width_;
	Vector2 cell = Vector2(x, y);
	VisitCell(cell);

	// the algorithm follows the following steps to create the maze:
	// from the chosen cell, we create a path, as long as can be
	// when the path finds a cell that is already a part of the maze (and it cannot be extended in any other direction)
	// another cell is chosen to start a new path, until the whole maze has been created
	do
	{
		kill(cell);
	} while ((cell = hunt()) != invalidDir_);

	//createGaps();
}

void MazeCreator::writeMap(std::string file)
{
	std::string path = "Assets/maps/" + file + ".map";
	std::ofstream f;
	f.open(path);
	int n = height_ * 2 + 1;
	f << n << "\n";           // height of the maze so it can be read afterwards
	n = width_ * 2 + 1;
	f << n << "\n";           // width of the maze so it can be read afterwards
	//TODO meter datos sobre el jugador, enemigos, numero de palancas.. lo necesario, antes de dibujar el mapa
	for (int i = 0; i < 2 * height_ + 1; i++)
	{
		for (int j = 0; j < 2 * width_ + 1; j++)
		{
			f << map_[i, j];
		}
		f << "\n";
	}

	//signature
	f << "Maze algorithm implemented by Ana Martin Sanchez" << "\n";
	f << "The Mechanic Lemon, QuackEngine :)" << "\n";
	f.close();
}
