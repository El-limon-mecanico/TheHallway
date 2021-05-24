#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Component.h"

class QuackEntity;
enum PrefabType;
const float WALL_SCALE = 5;

typedef std::pair<int, int> Vector2;
class MazeManager: public Component
{
private:
    int size_ = 20;                                    // ancho y alto del laberinto
    size_t numLevers_ = 0;                               // numero de manivelas por nivel
    int numGhosts_ = 0;                                 // numero de fantasmas por nivel
    int numEnemies_ = 0;                                // numero de enemigos (que recorren el laberinto) por nivel
    int pointsGhost_ = 0;                               // numero de puntos del recorrido para cada fantasma
    size_t additionalPaths_ = 0;                        // numero de paredes que se van a tirar de mas

    std::vector < std::vector<bool>> visitedCells_;     // para llevar un registro de las celdas que ya son parte del laberinto
    Vector2 invalidDir_;                                // por control
    Vector2 exit_;

    // para las manivelas que va a crear
    float chargeVel_ = 1;
    float unchargeVel_ = 1;

    // distancias de los enemigos (radar del jugador)
    float ghostRadar_ = 0;
    float enemyRadar_ = 0;

    std::vector<std::vector<char>> map_;
    char wallC_ = 'W';
    char floorC_ = '.';
    char leverC_ = 'L';
    char enemyC_ = 'E';
    char playerC_ = 'P';

    /// <summary>
    /// Creamos un laberinto con el algoritmo Hunt n Kill.
    /// Lo guardamos en un archivo de nombre filename.
    /// </summary>
    void createMaze();

    /// <summary>
    /// Parte de "kill" del algoritmo.
    /// Empezamos un camino aleatorio desde la posicion pos.
    /// En cada paso, se coge una direccion aleatoria para continuar el camino.
    /// Si no se puede seguir el camino en ninguna direccion, se acaba esta parte.
    /// </summary>
    void kill(Vector2 pos);

    /// <summary>
    /// Parte de "hunt" del algoritmo.
    /// Busca la primera celda (de izq. a derecha, de arriba abajo) que no forma parte del laberinto y que tenga un vecino visitado.
    /// Se tira la pared entre estas dos celdas y se sigue con la parte de "kill" desde aqui.
    /// Si hay varios vecinos visitados, se escoge uno al azar.
    Vector2 hunt();

    /// <summary>
    /// Tira la pared entre las celdas hunted y other.
    /// </summary>
    bool knockDownWall(Vector2 hunted, Vector2 other);

    /// <summary>
    /// Algortimo hunt n Kill
    /// </summary>
    void huntAndKill();

    /// <summary>
    /// Borra paredes aleatorias.
    /// Crea mas soluciones de las que habria originalmente (1)
    /// </summary>
    void createGaps();

    /// <summary>
    /// Escribe las manivelas en el mapa.
    /// Escribe la posicion que tendra la puerta cuando se active
    /// </summary>
    void createInteractables();

    /// <summary>
    /// Guarda un file con el mapa para poder leerlo despues.
    /// </summary>
    void writeMap();

    /// <summary>
    /// Borra las columnas que haya en el mapa (paredes que no tienen paredes vecinas)
    /// </summary>
    void eraseColumns();

    /// <summary>
    /// Situa al jugador en el mapa en una de las cuatro esquinas, aleatoriamente
    /// </summary>
    void spawnPlayer();

    QuackEntity* createObject(std::string tag, Vector3D pos, Vector3D scale, std::string name = "PT_CUBE", bool trig = false, Vector3D rot = Vector3D(0, 0, 0));
    void createOuterWalls();

    /// <summary>
    /// Actualiza la lista de celdas visitadas
    /// </summary>
    void VisitCell(Vector2 pos) { visitedCells_[pos.first][pos.second] = true; };

    Vector2 getArrayVector(Vector2 pos);
    void setCell(char c, Vector2 pos) { map_[(int)(pos.first)][(int)(pos.second)] = c; }
    bool validDir(Vector2 pos) { return (pos.first >= 0 && pos.first < size_&& pos.second >= 0 && pos.second < size_); };

public:
    MazeManager();
    ~MazeManager() {}
    virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
    virtual void start() override;
    static std::string GetName() { return "MazeManager"; }
    std::vector<std::vector<char>> getMap()const { return map_; }

    /// <summary>
    /// Las entidades en el mundo pueden preguntarle en que posicion del mapa (vector<vector<char>>) se encuentran.
    /// </summary>
    /// <param name="pos"></param>
    /// <returns></returns>
    Vector2 getPositionInMap(Vector3D pos);
    Vector3D getPositionInWorld(Vector2 pos, float y = 0);
    Vector2 getRandomFloor();

    void activateLever();

    // arriba, abajo, izquierda y derecha
    const std::vector<Vector2> DIRECTIONS{ Vector2(0,-1), Vector2(0,1),  Vector2(-1,0), Vector2(1,0) };
};

