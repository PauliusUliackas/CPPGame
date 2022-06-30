#include "Hitbox.hpp"

Hitbox::Hitbox(double x, double y, double width, double height)
{
    hitbox = sf::RectangleShape();
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(x, y);
};

Hitbox::~Hitbox(){};

bool Hitbox::intersects(Hitbox other)
{
    return hitbox.getGlobalBounds().intersects(other.hitbox.getGlobalBounds());
};

bool Hitbox::intersects(double x, double y, double width, double height)
{
    Hitbox hb(x, y, width, height);
    return intersects(hb);
};

double Hitbox::getX()
{
    return hitbox.getGlobalBounds().left;
};

double Hitbox::getY()
{
    return hitbox.getGlobalBounds().top;
};

double Hitbox::getHeight()
{
    return hitbox.getGlobalBounds().height;
};

double Hitbox::getWidth()
{
    return hitbox.getGlobalBounds().width;
};

void Hitbox::moveBy(double x, double y)
{   
    hitbox.move(x, y);
};

void Hitbox::render(sf::RenderWindow* g, sf::Color c)
{
    hitbox.setFillColor(c);
    g->draw(hitbox);
};

void Hitbox::setX(double x)
{
    hitbox.setPosition(x,getY());
};

void Hitbox::setY(double y)
{
    hitbox.setPosition(getX(),y);
};