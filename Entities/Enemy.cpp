#include "Enemy.hpp"

Enemy::Enemy(double x, double y, double width, double height) : Character(x, y, width, height)
{
    speed = 1;
    velocity.x = 0;
    velocity.y = 0;
}

Enemy::~Enemy(){}

void Enemy::AI(Player*)
{

};

void Enemy::update()
{   
    for(Token* t: collisions)
    {
        
        if(Firewall* fw = dynamic_cast<Firewall*>(t))
        {
            dealDamage(fw->dealDamage(this));
            continue;
        }
        
    }
};