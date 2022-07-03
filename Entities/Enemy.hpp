#pragma once

#include "../Entities/Player.hpp"

class Enemy : public Character
{

protected:
    double speed;
    std::vector<Skill*> skills;

public:
    Enemy(double, double, double, double);
    virtual ~Enemy();
    virtual void render(sf::RenderWindow*) = 0;
    virtual void update();
    virtual void AI(Player*);
    void clearSkills();
    std::vector<Skill*> getSkills();

};
