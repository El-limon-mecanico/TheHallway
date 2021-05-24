#pragma once
#include "Component.h"
#include <queue>

class Rigidbody;
class MazeManager;

class MazeRunner : public Component {
private:
	Transform* playerTr_ = nullptr;
	MazeManager* mazeMng_ = nullptr;
	
	float speed_ = 10;
	char floorC_ = '.';
	bool following_ = false;				// si sigue al jugador, el objetivo se actualizara 
	float timeToUpdate_ = 2.5;				// cada cuanto tiempo vuelve a buscar el objetivo
	float timeFollowing_ = 0;				// tiempo que lleva siguiendo al jugador (para no actualizar el camino en cada update)
	float triggerDistance_ = 25;				// distancia a la que detecta (o pierde) al jugador
	std::pair<int, int> objective_;			// objetivo que va a buscar
	std::list<std::pair<int, int>>path_;

	
	/// <summary>
	/// Encuentra el camino mas corto desde la posicion actual al objetivo.
	/// Utiliza una version de BFS en la que el grafo esta representado como un vector<vector<char>>.
	/// Solo son adyacentes las celdas que sean suelo
	/// </summary>
	/// <returns>True si hay camino hasta el punto; false en otro caso.</returns>
	bool findPath();

	void move();
	void smoothPath();
	void setObjective();

	bool inline sameDirection(std::pair<int, int> a, std::pair<int, int> b);
public:

	MazeRunner() {}
	~MazeRunner() {}

	void getPlayer();
	void setSpeed(float s) { speed_ = s; }
	void setFloorChar(char c) { floorC_ = c; }
	void setDistance(float d) { triggerDistance_ = d; }
	void setManager(MazeManager* maze) { mazeMng_ = maze; }
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }
	virtual void start();
	virtual void update();

	static std::string GetName() { return "MazeRunner"; }
};