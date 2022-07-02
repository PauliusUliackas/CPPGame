#pragma once

#include "Skill.hpp"
#include "../DataStructures/DeltaTime.hpp"
#include "../Entities/Character.hpp"
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
    Firewall(double, double);
    ~Firewall();
    void render(sf::RenderWindow*);
    void activate(Tile&);
    bool canActivate(Tile& tile);
    Firewall* copy();
    bool isOver();
    int dealDamage(Character*);
};
