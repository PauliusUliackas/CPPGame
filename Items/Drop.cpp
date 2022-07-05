#include "Drop.hpp"


Drop::Drop(std::string icon) : Token(0, 0, 16, 16)
{
    texture.loadFromFile("Art/" +icon+".png");
    sprite.setTexture(texture);
    sprite.scale(2,2);
}

Drop::~Drop()
{
}

void Drop::render(sf::RenderWindow* g)
{
    g->draw(sprite);
};

void Drop::place(double x, double y)
{
    sprite.setPosition(x,y);
}