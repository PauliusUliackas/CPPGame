#include "Character.hpp"

Character::Character(double x, double y, double width, double height) : Token(x,y,width,height)
{
    health = 100;
};

Character::~Character()
{
};

void Character::render(sf::RenderWindow* g)
{
    hitbox.render(g);
};

void Character::update()
{
    velocity.x = 0;
    velocity.y = 0;
};

void Character::setCollisions(std::vector<Token*> collisions)
{
    this->collisions = collisions;
};

std::vector<Token*>& Character::getCollisions()
{
    return collisions;
};

sf::Vector2f Character::speed()
{
    return velocity;
};

void Character::dealDamage(int ticks)
{
    health -= ticks;
    /*
    if(ticks != 0)
        std::cout<<health<<std::endl;
        */
};

bool Character::dead()
{
    return health <= 0;
};

int Character::HP()
{
    return health;
}
