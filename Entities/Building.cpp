#include "Building.hpp"

Building::Building(double x, double y, std::string name, double width, int scale) : Token(x, y, width*scale, width*scale)
{
    anime.load("main", name, width);
    anime.scale("main", scale, scale);
    anime.select("main");
    anime.resume();
    solid = true;
    hitbox.setHeight(anime.getSize().y);
}

Building::~Building()
{
}

void Building::render(sf::RenderWindow* g)
{
    hitbox.render(g);
    anime.play(g, hitbox.getX(), hitbox.getY());
}

void Building::setSolid(bool solid)
{
    this->solid = solid;
};