#pragma once

#include "../Skills/Skill.hpp"

class Healthpot : public Skill
{
private:
    Character* user;

public:
    Healthpot(double x, double y, int state);
    ~Healthpot();
    void activate(Tile& location, sf::Vector2f from);
    bool canActivate(Tile& tile, Character* c);
    Healthpot* copy();
};
