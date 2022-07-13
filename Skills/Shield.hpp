#pragma once

#include "Skill.hpp"

class Shield : public Skill
{
private:
    Tile* activeOn;
    float length;
    float curr;
public:
    Shield(double, double, int);
    ~Shield();
    void render(sf::RenderWindow*);
    void activate(Tile&, sf::Vector2f from);
    bool canActivate(Tile& tile, Character* c);
    Shield* copy();
    bool isOver();
};
