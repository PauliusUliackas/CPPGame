#include "Skill.hpp"


Skill::Skill(std::string name, double x, double y, int state) : Token(x, y, 20, 20), anime(8)
{
    solid = false;
    obj = false;
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
    if(state == PICKED) return;

    if(state == DROP)
    {
        icon.setPosition(hitbox.getX(), hitbox.getY());
        g->draw(icon);
    }
};

void Skill::update()
{};

bool Skill::equals(Skill* skill)
{
    return name == skill->name;
};

bool Skill::canActivate(Tile& tile, Character* c)
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
};


double Skill::magnitude(sf::Vector2f vec)
{
    return std::sqrt(std::pow(vec.x,2)+std::pow(vec.y,2));
};

sf::Vector2f Skill::sub(sf::Vector2f vec1,sf::Vector2f vec2)
{
    return sf::Vector2f(vec1.x - vec2.x, vec1.y - vec2.y);
};

sf::Vector2f Skill::add(sf::Vector2f vec1,sf::Vector2f vec2)
{
    return sf::Vector2f(vec1.x + vec2.x, vec1.y + vec2.y);
};

sf::Vector2f Skill::mult(sf::Vector2f vec1,double vec2)
{
    return sf::Vector2f(vec1.x * vec2, vec1.y * vec2);
};

sf::Vector2f Skill::div(sf::Vector2f vec1,double vec2)
{
    return mult(vec1, 1.0/vec2);
};

sf::Vector2f Skill::normalise(sf::Vector2f vec1)
{
    return div(vec1, magnitude(vec1));
};

void Skill::setActive()
{
    state = ACTIVE;
};

void Skill::addCollision(Token* t)
{
    collisions.push_back(t);
};
