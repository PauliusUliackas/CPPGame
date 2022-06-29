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
    
};

void Character::setCollisions(std::vector<Token*> collisions)
{
    this->collisions = collisions;
};

std::vector<Token*>& Character::getCollisions()
{
    return collisions;
};
