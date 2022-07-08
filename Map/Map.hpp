#pragma once

#include "Tile.hpp"
#include "../Engine/TokenHandler.hpp"
#include "../Entities/ExitPoint.hpp"
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

class Map
{
private:
    std::vector<Tile*> grid;
    std::vector<Tile*> spawns;
    std::vector<Building*> buildings;
    Tile* slected;
    
public:
    Map();
    ~Map();
    void render(sf::RenderWindow*, Hitbox);
    void load(sf::Vector2f dimentions);
    Tile& getSelected();
    Tile* getRandomSpawn();
};
