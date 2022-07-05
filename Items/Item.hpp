#pragma once

#include "../Entities/Character.hpp"
#include "../Map/Tile.hpp"

class Item : public Token
{
private:
    Animation anime;
public:
    Item();
    ~Item();
    virtual void activate(double, double, double, double) = 0;
    virtual void canActivate(Tile& t, Character* c) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow*) = 0;

};
