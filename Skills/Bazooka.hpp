#pragma once
#include "Skill.hpp"

class Bazooka : public Skill
{
private:
    double speed;
    sf::Vector2f velocity;
    bool collided;
    bool immuneToPlayer;
    double distance;
    sf::Vector2f from;
    
public:
    Bazooka(double x, double y, int state, bool);
    ~Bazooka();
    void render(sf::RenderWindow*);
    void update();
    void activate(Tile& location, sf::Vector2f from);
    void shoot(sf::Vector2f, sf::Vector2f);
    bool canActivate(Tile& tile, Character* c);
    Bazooka* copy();
    bool isOver();
    int damage();
    bool isImmuneToPlayer();
};
