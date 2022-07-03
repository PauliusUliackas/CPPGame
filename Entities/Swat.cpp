#include "Swat.hpp"

Swat::Swat(double x, double y) : Enemy(x,y,40,40)
{
    speed = 5;
    health = 25;
}

Swat::~Swat()
{
}

void Swat::render(sf::RenderWindow* g)
{
    hitbox.render(g, sf::Color::Blue);
}

void Swat::update()
{
    Enemy::update();
}

void Swat::AI(Player* p)
{
    Enemy::AI(p);
    double length = 150;
    double x1 = p->getHB().getX();
    double y1 = p->getHB().getY();
    double x2 = getHB().getX();
    double y2 = getHB().getY();

    double distance= std::sqrt(std::pow(x2-x1,2) + std::pow(y2-y1,2));

    if(distance < length)
    {
        if(x1 < x2) velocity.x = speed;
        else if (x1 > x2) velocity.x = -speed;

        if(y1 < y2) velocity.y = speed;
        else if(y1 > y2) velocity.y = -speed;
    }
    else if(distance > 500)
    {
        if(x1 < x2) velocity.x = -speed;
        else if (x1 > x2) velocity.x = speed;

        if(y1 < y2) velocity.y = -speed;
        else if(y1 > y2) velocity.y = speed;
    }
    else
    {
        velocity.x = 0;
        velocity.y = 0;
    }
}