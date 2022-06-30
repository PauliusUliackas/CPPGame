#include "Tile.hpp"

Tile::Tile(double x, double y):
hitbox(x,y, 50, 50)
{
    this->texture.loadFromFile("Art/Tile.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    occupied = false;
};

Tile::~Tile()
{
};

void Tile::render(sf::RenderWindow* g, sf::Color c)
{
    g->draw(sprite);
    hitbox.render(g, c);
};

Hitbox& Tile::getHitbox()
{
    return hitbox;
};

Hitbox Tile::getTile()
{
    return hitbox;
};

bool Tile::isOccupied()
{
    return occupied;
};

void Tile::setOccupied(bool x)
{
    occupied = x;
};