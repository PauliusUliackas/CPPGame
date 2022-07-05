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
    anime.load("Fire", "Fire", 25);
    anime.scale("Fire", 2, 2);
    anime.select("Fire");
}

Firewall::~Firewall()
{
    activeOn->setOccupied(false);
};

void Firewall::render(sf::RenderWindow* g)
{
    if(state == PICKED) return;
    
    if(state == DROP)
    {
        icon.setPosition(hitbox.getX(), hitbox.getY());
        g->draw(icon);
    }

    if(state == ACTIVE) 
    {
        anime.resume();
        anime.play(g, hitbox.getX(), hitbox.getY() - (90 - 48));
    }
};

void Firewall::activate(Tile& location, sf::Vector2f from)
{
    Skill::activate(location, from);
    hitbox = location.getTile();
    activeOn = &location;
    activeOn->setOccupied(true);
};

bool Firewall::canActivate(Tile& tile, Character* c)
{
    double length = 500;
    double x1 = c->getHB().getX();
    double y1 = c->getHB().getY();
    double x2 = tile.getHitbox().getX();
    double y2 = tile.getHitbox().getY();
    if( std::sqrt(std::pow(x2-x1,2) + std::pow(y2-y1,2)) > length) return false;
    return Skill::canActivate(tile, c) && !tile.isOccupied();
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