#pragma once

#include "Token.hpp"
#include <vector>
#include <iostream>

class Character : public Token
{
protected:
    sf::Vector2f velocity;
    std::vector<Token*> collisions;
    int health;

public:
    Character(double x, double y, double width, double height);
    ~Character();
    virtual void update();
    virtual void render(sf::RenderWindow*);

    sf::Vector2f speed();
    void setCollisions(std::vector<Token*>);
    std::vector<Token*>& getCollisions();

    virtual void dealDamage(int);
};