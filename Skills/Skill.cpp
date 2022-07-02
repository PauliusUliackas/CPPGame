#include "Skill.hpp"


Skill::Skill(std::string name, double x, double y, int state) : Token(x, y, 20, 20)
{
    solid = false;
    this->name = name;
    this->state = STATE::DROP;
    if(state == 1) this->state = STATE::PICKED;
    if(state == 2) this->state = STATE::ACTIVE;
};

Skill::~Skill()
{
    
};

void Skill::render(sf::RenderWindow* g)
{
};

bool Skill::equals(Skill* skill)
{
    return name == skill->name;
};

bool Skill::canActivate(Tile& tile)
{
    return state == PICKED;
};

std::string Skill::namae()
{
    return name;
};

void Skill::activate(Tile& location)
{
    state = STATE::ACTIVE;
};

Skill* Skill::copy()
{
    return new Skill(name, hitbox.getX(), hitbox.getY(), state);
};

bool Skill::isOver()
{
    return state == STATE::ACTIVE;
};

sf::Sprite Skill::getIcon()
{
    return this->icon;
};

bool Skill::canPickUp()
{
    return state == DROP;
};

void Skill::pickUp()
{
    state = PICKED;
}