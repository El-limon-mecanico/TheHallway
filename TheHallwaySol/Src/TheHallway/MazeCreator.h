#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Component.h"

class QuackEntity;
enum PrefabType;
const float WALL_SCALE = 1;

typedef std::pair<int, int> Vector2;
class MazeCreator: public Component
{
public:
    MazeCreator();
    ~MazeCreator() {}
    virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
    virtual void start() override;

    Vector2 getArrayVector(Vector2 pos);
    void setCell(char c, Vector2 pos) { map_[(int)(pos.first)][(int)(pos.second)] = c; }
    bool validDir(Vector2 pos) { return (pos.first >= 0 && pos.first < width_&& pos.second >= 0 && pos.second < width_); };
    static std::string GetName() { return "MazeCreator"; }


    /// <summary>
    /// Actualiza la lista de celdas visitadas
    /// </summary>
    void VisitCell(Vector2 pos) { visitedCells_[pos.first][pos.second] = true; };


private:
    int width_ = 20;                                    // ancho y alto del laberinto
    size_t additionalPaths_ = 0;                        // numero de paredes que se van a tirar de mas

    std::vector < std::vector<bool>> visitedCells_;     // para llevar un registro de las celdas que ya son parte del laberinto
    Vector2 invalidDir_;                                // por control

    std::string filename = "";
    std::vector<std::vector<char>> map_;
    char floorC_ = '.';            
    char wallC_ = 'W';             
    char playerC_ = 'P';

    // arriba, abajo, izquierda y derecha
    std::vector<Vector2> DIRECTIONS{ Vector2(0,-1), Vector2(0,1),  Vector2(-1,0), Vector2(1,0) };

    // ----------------------------------- MAZE CREATION ----------------------------------- //

    /// <summary>
    /// Creamos un laberinto con el algoritmo Hunt n Kill.
    /// Lo guardamos en un archivo de nombre filename.
    /// </summary>
    void createMaze(std::string filename);

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
    /// Guarda un file con el mapa para poder leerlo despues.
    /// </summary>
    void writeMap(std::string file);

    /// <summary>
    /// Borra las columnas que haya en el mapa (paredes que no tienen paredes vecinas)
    /// </summary>
    void eraseColumns();

    // ------------------------------------------------------------------------------------- //


    // --------------------------------- AUXILIARY METHODS --------------------------------- //

    //TODO: Que no sea siempre en el mismo punto
    /// <summary>
    /// Situa al jugador en el mapa
    /// </summary>
    void spawnPlayer()
    {
        // change the map file as to include the player
        map_[1][1] = playerC_;
    }

    QuackEntity* createObject(Vector3D pos, Vector3D scale, std::string name = "PT_CUBE", Vector3D rot = Vector3D(0, 0, 0));
    void createOuterWalls();
    // ------------------------------------------------------------------------------------- //
};

