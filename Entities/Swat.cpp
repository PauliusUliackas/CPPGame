#include "Swat.hpp"

Swat::Swat(double x, double y) : Enemy(x,y,40,40)
{
    speed = 5;
    health = 25;
    timer = 30;
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
    timer += DeltaTime::get();
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

        if(timer < 30) return;
        timer = 0;

        velocity.x = 0;
        velocity.y = 0;
        Bazooka* bz = new Bazooka(0,0,1, false);
        bz->setActive();
        bz->shoot(sf::Vector2f(hitbox.getX(), hitbox.getY()), sf::Vector2f(p->getHB().getX(), p->getHB().getY()));
        skills.push_back(bz);
    }
}

Skill* Swat::drop()
{
    return new Bazooka(hitbox.getX(),hitbox.getY(),0,true);
}