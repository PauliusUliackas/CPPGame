#pragma once
#include "Skill.hpp"

class Bazooka : public Skill
{
private:
    double speed;
    sf::Vector2f velocity;
    sf::Vector2f from;
    bool collided;
    bool immuneToPlayer;
    double distance;
    
public:
    Bazooka(double x, double y, int state, bool);
    ~Bazooka();
    void render(sf::RenderWindow*);
    void update();
    void activate(Tile& location);
    void shoot(sf::Vector2f, sf::Vector2f);
    bool canActivate(Tile& tile, Character* c);
    Bazooka* copy();
    bool isOver();
    int damage();
    bool isImmuneToPlayer();
};
