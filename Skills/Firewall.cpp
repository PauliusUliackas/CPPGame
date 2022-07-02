#include "Firewall.hpp"

Firewall::Firewall(double x, double y, int state) : 
Skill("Firewall", x, y, state)
{
    length = 40;
    curr = 0;
    damageCounter = 0;
    texture.loadFromFile("Art/FireIcon.png");
    icon.setTexture(texture);
    icon.scale(4,4);
}

Firewall::~Firewall()
{
    activeOn->setOccupied(false);
};

void Firewall::render(sf::RenderWindow* g)
{
    if(state == PICKED) return;
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
    return new Firewall(getHB().getX(), getHB().getY(), state);
};

bool Firewall::isOver()
{
    for(auto &pair: damage)
    {
        pair.second += DeltaTime::get();
    }
    curr += DeltaTime::get();
    return (Skill::isOver() && curr >= length); 
};

int Firewall::dealDamage(Character* c)
{
    if(state != STATE::ACTIVE) return 0;

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