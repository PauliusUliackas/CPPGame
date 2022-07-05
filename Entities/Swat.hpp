#pragma once

#include "Enemy.hpp"
#include "../Skills/Bazooka.hpp"

class Swat : public Enemy
{
private:
    double timer;
    
public:
    Swat(double x, double y);
    ~Swat();
    void render(sf::RenderWindow*);
    void update();
    virtual void AI(Player*);
    Skill* drop();
    Swat* spawn(double x, double y);
};
