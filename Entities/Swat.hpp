#pragma once

#include "Enemy.hpp"

class Swat : public Enemy
{
private:
    /* data */
public:
    Swat(double x, double y);
    ~Swat();
    void render(sf::RenderWindow*);
    void update();
    virtual void AI(Player*);
};
