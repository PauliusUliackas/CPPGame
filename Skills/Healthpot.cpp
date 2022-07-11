#include "Healthpot.hpp"

Healthpot::Healthpot(double x, double y, int state) : Skill("HealthPot", x, y, state)
{
    rarity = 2;
    texture.loadFromFile("Art/HealthPotIcon.png");
    icon.setTexture(texture);
    icon.scale(4,4);
    isPicked = false;
};

Healthpot::~Healthpot()
{
};

void Healthpot::activate(Tile& location, sf::Vector2f from)
{
    Skill::activate(location, from);
    user->dealDamage(-3);
};

bool Healthpot::canActivate(Tile& tile, Character* c)
{
    user = c;
    return Skill::canActivate(tile, c);
};

Healthpot* Healthpot::copy()
{
    return new Healthpot(0,0,state);
};