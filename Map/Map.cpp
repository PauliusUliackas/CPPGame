#include "Map.hpp"

Map::Map()
{

};

Map::~Map()
{

};

void Map::render(sf::RenderWindow* g, Hitbox mouse)
{
    for(Tile* t: grid)
    {
        if(mouse.intersects(t->getHitbox()))
        {
            t->render(g, sf::Color::Red);
            slected = t;
        } 
        else
        {
            t->render(g);
        }
    }
};

void Map::load(sf::Vector2f dimentions)
{
    srand(time(NULL));
    for(int i = 0; i<dimentions.y; i+= 50)
    {
        for(int j = 0; j < dimentions.x; j+= 50)
        {
            Tile* mapTile = new Tile(j, i);
            if(TokenHandler::intialiseMap(mapTile->getHitbox()))
            {
                mapTile->setOccupied(true);
            }
            else
            {
                spawns.push_back(mapTile);
                mapTile->setOccupied(false);
            }
            grid.push_back(mapTile);
        }
    }
};

Tile& Map::getSelected()
{
    return *slected;
};

Tile* Map::getRandomSpawn()
{
    return spawns.at(std::rand() % spawns.size());
};