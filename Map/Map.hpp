#pragma once

#include "Tile.hpp"
#include "../Engine/TokenHandler.hpp"
#include <vector>

class Map
{
private:
    std::vector<Tile*> grid;
    Tile* slected;
    
public:
    Map();
    ~Map();
    void render(sf::RenderWindow*, Hitbox);
    void load(sf::Vector2f dimentions);
    Tile& getSelected();
};
