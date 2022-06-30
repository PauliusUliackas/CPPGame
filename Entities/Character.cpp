#include "Character.hpp"

Character::Character(double x, double y, double width, double height) : Token(x,y,width,height)
{

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
}
