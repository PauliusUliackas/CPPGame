#pragma once

#include "Skill.hpp"
#include "../Entities/Player.hpp"

class GoldBag : public Skill
{
private:
    Player* player;
public:
    GoldBag(double, double, int);
    ~GoldBag();
    void activate(Tile& location, sf::Vector2f from);
    bool canActivate(Tile& tile, Character* c);
    GoldBag* copy();
};
