#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Component.h"


typedef std::pair<int, int> Vector2;
class MazeCreator: public Component
{
public:
    MazeCreator() {}
    ~MazeCreator() {}
    virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;


    void setSquareMaze(bool square) { squareMaze_ = square; }


private:
    int width_ = 20, height_ = 20;                      // ancho y alto del laberinto
    size_t additionalPaths_ = 0;                        // numero de paredes que se van a tirar de mas
    bool squareMaze_ = true;                            // if (squareMaze_), height = width

    std::vector < std::vector<bool>> visitedCells_;     // para llevar un registro de las celdas que ya son parte del laberinto
    Vector2 invalidDir_;                                // por control

    std::vector<std::string> map_;
    const char floorC_ = '.';            // luego los cambiamos
    const char wallC_ = 'W';             // o los leemos por archivo
    const char playerC_ = 'P';

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
    bool knockDownWall(Vector2 hunted, Vector2 other)
    {
        //direccion (hunted POV)
        Vector2 direccion;
        direccion.first = other.first - hunted.first;
        direccion.second = other.second - hunted.second;
        hunted = getRealVector(hunted);

        hunted.first += direccion.first;
        hunted.second += direccion.second;

        // si ya se ha derribado, no se puede volver a tirar
        if (map_[hunted.first][hunted.second] != wallC_)
            return false;

        setCell(floorC_, hunted);
        return true;
    }

    /// <summary>
    /// Algortimo hunt n Kill
    /// </summary>
    void huntAndKill();

    /// <summary>
    /// Borra paredes aleatorias.
    /// Crea mas soluciones de las que habria originalmente (1)
    /// </summary>
    void createGaps()
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

    /// <summary>
    /// Guarda un file con el mapa para poder leerlo despues.
    /// </summary>
    void writeMap(std::string file);

    /// <summary>
    /// Borra las columnas que haya en el mapa (paredes que no tienen paredes vecinas)
    /// </summary>
    void eraseColumns()
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

                // checks if there is any wall beside the "column"
                while (loops < DIRECTIONS.size() && !wall)
                {
                    // if it is a floor cell, it cannot be a column
                    if (map_[dir.first][dir.second] == wallC_)
                    {
                        other.first = dir.first + DIRECTIONS[loops].first;
                        other.second = dir.second + DIRECTIONS[loops].second;

                        // if there is a wall beside the "column", it is not a column
                        if (map_[other.first][other.second] == wallC_)
                            wall = true;
                    }
                    loops++;
                }

                // if it is a column, it becomes a floor cell
                if (!wall)
                    map_[dir.first][dir.second] = floorC_;
            }
        }
    }
    // ------------------------------------------------------------------------------------- //


    // --------------------------------- AUXILIARY METHODS --------------------------------- //
    /// <summary>
    /// Traduce de posicion en el mundo a posicion en el array
    /// </summary>
    Vector2 getRealVector(Vector2 pos)
    {
        Vector2 realPos = pos;
        realPos.first *= 2; realPos.second *= 2;
        realPos.first += 1; realPos.second += 1;

        return realPos;
    }

    /// <summary>
    /// Cambia el mapa en pos.
    /// </summary>
    void setCell(char c, Vector2 pos)
    {
        map_[(int)(pos.first), (int)(pos.second)] = c;
    }

    /// <summary>
    /// Valida si no se sale de los limites del mapa
    /// </summary>
    bool validDir(Vector2 pos)
    {
        return (pos.first >= 0 && pos.first < width_&&
            pos.second >= 0 && pos.second < height_);
    }

    /// <summary>
    /// Actualiza la lista de celdas visitadas
    /// </summary>
    void VisitCell(Vector2 pos)
    {
        visitedCells_[pos.first][pos.second] = true;
    }

    //TODO: Que no sea siempre en el mismo punto
    /// <summary>
    /// Situa al jugador en el mapa
    /// </summary>
    void spawnPlayer()
    {
        // change the map file as to include the player
        map_[1, 1] = playerC_;
    }

    // ------------------------------------------------------------------------------------- //
};

