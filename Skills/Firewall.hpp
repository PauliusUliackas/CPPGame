#pragma once

#include "Skill.hpp"
#include "../DataStructures/DeltaTime.hpp"

class Firewall : public Skill
{
private:
    Tile* activeOn;
    float length;
    float curr;

public:
    Firewall(double, double);
    ~Firewall();
    void render(sf::RenderWindow*);
    void activate(Tile&);
    bool canActivate(Tile& tile);
    Firewall* copy();
    bool isOver();
};
