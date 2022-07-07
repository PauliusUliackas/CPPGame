#pragma once

#include "../Entities/Player.hpp"

class Enemy : public Character
{

protected:
    double speed;
    std::vector<Skill*> skills;

    int maxMoney, minMoney;

public:
    Enemy(double, double, double, double);
    virtual ~Enemy();
    virtual void render(sf::RenderWindow*);
    virtual void update();
    virtual void AI(Player*);
    void clearSkills();
    std::vector<Skill*> getSkills();

    virtual Skill* drop();
    virtual Enemy* spawn(double x, double y);

    int money();

};
