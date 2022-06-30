#include "Skill.hpp"


Skill::Skill(std::string name, double x, double y) : Token(x, y, 20, 20)
{
    solid = false;
    state = STATE::PICKED;
    this->name = name;
};

Skill::~Skill()
{
    
};

void Skill::render(sf::RenderWindow* g){};

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
    return new Skill(name, hitbox.getX(), hitbox.getY());
};

bool Skill::isOver()
{
    return state == STATE::ACTIVE;
};