#pragma once

#include "Token.hpp"

class Building : public Token
{
public:
    Building(double x, double y, std::string name, double width, int scale = 1);
    ~Building();
    virtual void render(sf::RenderWindow*);
    void setSolid(bool);
};
