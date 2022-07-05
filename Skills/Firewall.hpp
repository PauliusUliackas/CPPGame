#pragma once

#include "Skill.hpp"
#include "../DataStructures/DeltaTime.hpp"
#include <unordered_map>

class Firewall : public Skill
{
private:
    Tile* activeOn;
    float length;
    float curr;
    float damageCounter;
    std::unordered_map<Character*, float> damage;

public:
    Firewall(double, double, int);
    ~Firewall();
    void render(sf::RenderWindow*);
    void activate(Tile&, sf::Vector2f from);
    bool canActivate(Tile& tile, Character* c);
    Firewall* copy();
    bool isOver();
    int dealDamage(Character*);
};
