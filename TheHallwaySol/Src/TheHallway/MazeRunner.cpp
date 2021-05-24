#include "MazeRunner.h"
#include "MazeManager.h"
#include "QuackEntity.h"
#include "SceneMng.h"
#include "QuackEnginePro.h"
#include "Rigidbody.h"

#include "InputManager.h"

typedef std::vector<std::vector<char>> map;
void MazeRunner::setObjective()
{
	// si seguimos al jugador, buscamos la posicion en la que esta
	// si no, vamos a un punto cualquiera
	assert(mazeMng_);
	if (following_)
	{
		objective_ = mazeMng_->getPositionInMap(playerTr_->position());
		findPath();
	}
	else
	{
		// el punto tiene que ser accesible
		do {
			objective_ = mazeMng_->getRandomFloor();

		} while (!findPath());
	}

	// suavizamos el camino para guardar menos nodos
	smoothPath();
}

bool MazeRunner::findPath()
{
	map maze = mazeMng_->getMap();
	Vector2 src = mazeMng_->getPositionInMap(entity_->transform()->position());
	path_.clear();

	std::vector<std::vector<int>>distance(maze.size(), std::vector(maze.size(), INT_MAX));
	std::vector<std::vector<bool>>visited(maze.size(), std::vector(maze.size(), false));
	std::vector<std::vector<Vector2>>last(maze.size(), std::vector(maze.size(), Vector2(-1,-1)));
	std::list<Vector2>nodes;

	nodes.push_back(src);
	distance[src.first][src.second] = 0;
	visited[src.first][src.second] = true;
	
	// algoritmo bfs, pero cortamos cuando lleguemos al destino
	while (!nodes.empty() && !visited[objective_.first][objective_.second])
	{
		Vector2 vec = nodes.front(); nodes.pop_front();
		for (int i = 0; i < mazeMng_->DIRECTIONS.size(); i++)
		{
			// si es suelo lo consideramos adyacente
			Vector2 aux; 
			aux.first = vec.first + mazeMng_->DIRECTIONS[i].first;
			aux.second = vec.second + mazeMng_->DIRECTIONS[i].second;

			if (maze[aux.first][aux.second] == floorC_ && !visited[aux.first][aux.second])
			{
				last[aux.first][aux.second] = vec;
				visited[aux.first][aux.second] = true;
				nodes.push_back(aux);
			}
		}
	}

	// metemos el camino que hayamos calculado
	for (Vector2 aux = objective_; aux != src; aux = last[aux.first][aux.second])
	{
		path_.push_front(aux);
	}
	path_.push_front(src);
	return visited[objective_.first][objective_.second];
}

void MazeRunner::move()
{
	// nos movemos en direccion al siguiente punto del path
	// nos movemos al centro de la casilla (no a la esquina superior izquierda)
	Vector3D obj = mazeMng_->getPositionInWorld(path_.front(), transform->position().y);
	float distance = (obj - transform->position()).magnitude();
	
	// si estamos lo suficientemente cerca del centro de la casilla, pasamos al siguiente objetivo
	if (distance < WALL_SCALE * 0.25)
	{
		path_.pop_front(); 
		if (!path_.empty())
		{
			obj = mazeMng_->getPositionInWorld(path_.front(), transform->position().y);
		}
	}
	transform->lookAt(obj);
	entity_->getComponent<Rigidbody>()->setVelocity(transform->forward * speed_);
}

void MazeRunner::smoothPath()
{
	// lista en la que solo vamos a guardar los valores necesarios
	std::list<Vector2> aux; aux.push_back(path_.front());
	path_.pop_front();
	
	// si la direccion anterior->actual es igual a la direccion actual->siguiente
	// podemos borrar el nodo actual. De lo contrario, es un punto necesario
	Vector2 nextDir, pastDir, actual;
	while (path_.size() > 1)
	{
		actual = path_.front(); path_.pop_front();
		pastDir.first = actual.first - aux.back().first; pastDir.second = actual.second - aux.back().second;
		nextDir.first = path_.front().first - actual.first; nextDir.second = path_.front().second - actual.second;

		if (!sameDirection(pastDir, nextDir))
		{
			aux.push_back(actual);
		}
	}
	
	// guardamos el destino como parte final del camino
	if (!path_.empty())
	{
		aux.push_back(path_.front());
	}

	// guardamos el camino
	path_ = aux;
}

inline bool MazeRunner::sameDirection(Vector2 a, Vector2 b)
{
	return (a.first < 0 && b.first < 0) || (a.first > 0 && b.first > 0) ||
		(a.second < 0 && b.second < 0) || (a.second > 0 && b.second > 0);
}

void MazeRunner::getPlayer()
{
	assert(SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player"));
	playerTr_ = SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player")->transform();
}

void MazeRunner::start()
{
	getPlayer();
}

void MazeRunner::update()
{
	// si nos acercamos al jugador, empezamos a seguirle.
	// si nos alejamos, dejamos de seguirle
	float distance = (playerTr_->position() - transform->position()).magnitude();
	if (distance< triggerDistance_)
	{
		following_ = true;
	}
	else
	{
		// si acabamos de perder al jugador, nos ponemos otro objetivo
		bool aux = following_;
		following_ = false;
		if (aux)
		{
			setObjective();
		}
	}

	if (following_)
	{
		// cada cierto tiempo actualizamos el objetivo
		if (timeFollowing_ > timeToUpdate_)
		{
			timeFollowing_ = 0;
			setObjective();
		}
		else
		{
			timeFollowing_ += QuackEnginePro::Instance()->time()->deltaTime();
		}
	}
	if (path_.empty()) setObjective();
	move();
}
