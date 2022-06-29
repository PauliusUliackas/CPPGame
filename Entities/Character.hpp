#pragma once

#include "Token.hpp"
#include <vector>

class Character : public Token
{
private:
    sf::Vector2f velocity;
    std::vector<Token*> collisions;

public:
    Character(double x, double y, double width, double height);
    ~Character();
    virtual void update();
    virtual void render(sf::RenderWindow*);

    void setCollisions(std::vector<Token*>);
    std::vector<Token*>& getCollisions(); 
};