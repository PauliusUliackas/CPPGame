#pragma once

#include "../DataStructures/Hitbox.hpp"
#include <SFML/Graphics.hpp>

class Tile
{
private:
    Hitbox hitbox;
    sf::Texture texture;
    sf::Sprite sprite;
    bool occupied;

public:
    Tile(double x, double y);
    ~Tile();
    void render(sf::RenderWindow* g, sf::Color = sf::Color{0,0,0,0});
    Hitbox& getHitbox();
    Hitbox getTile();
    bool isOccupied();
    void setOccupied(bool);
};
