#include "Enemy.hpp"
#include "../Engine/TokenHandler.hpp"

Enemy::Enemy(double x, double y, double width, double height) : Character(x, y, width, height)
{
    speed = 1;
    velocity.x = 0;
    velocity.y = 0;

    maxMoney = 15;
    minMoney = 5;
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

        if(Bazooka* b = dynamic_cast<Bazooka*>(t))
        {
            if(b->isImmuneToPlayer())
            {
                dealDamage(b->damage());
            }
            continue;
        }
        
    }
};

void Enemy::clearSkills()
{
    skills.clear();
};

std::vector<Skill*> Enemy::getSkills()
{
    return skills;
};

Skill* Enemy::drop()
{
    return nullptr;
};

Enemy* Enemy::spawn(double, double)
{
    return nullptr;
};

void Enemy::render(sf::RenderWindow*){};

int Enemy::money()
{
    return std::rand()%(maxMoney-minMoney + 1)+minMoney;
};