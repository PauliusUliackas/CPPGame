#include "Firewall.hpp"

Firewall::Firewall(double x, double y) : 
Skill("Firewall", x, y)
{
    length = 40;
    curr = 0;
    damageCounter = 0;
}

Firewall::~Firewall()
{
    activeOn->setOccupied(false);
};

void Firewall::render(sf::RenderWindow* g)
{
    hitbox.render(g, sf::Color{255,127,80,255});
};

void Firewall::activate(Tile& location)
{
    Skill::activate(location);
    hitbox = location.getTile();
    activeOn = &location;
    activeOn->setOccupied(true);
};

bool Firewall::canActivate(Tile& tile)
{
    return Skill::canActivate(tile) && !tile.isOccupied();
};

Firewall* Firewall::copy()
{
    return new Firewall(getHB().getX(), getHB().getY());
};

bool Firewall::isOver()
{
    for(auto &pair: damage)
    {
        pair.second += DeltaTime::get();
    }
    curr += DeltaTime::get();
    return Skill::isOver() && curr >= length; 
};

int Firewall::dealDamage(Character* c)
{
    if(damage.find(c) == damage.end())
    {
        damage[c] = 0;
    }
    else if(damage[c] >= 10)
    {
        damage.erase(c);
        return 5;
    }
    return 0;
};