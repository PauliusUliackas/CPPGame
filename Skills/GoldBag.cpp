#include "GoldBag.hpp"

GoldBag::GoldBag(double x, double y, int state) : Skill("GoldBag", x, y, state)
{
    rarity = 4;
    texture.loadFromFile("Art/GoldBagIcon.png");
    icon.setTexture(texture);
    icon.scale(4,4);
    isPicked = false;
    std::srand(time(NULL));
}

GoldBag::~GoldBag()
{
}

void GoldBag::activate(Tile& location, sf::Vector2f from)
{
    Skill::activate(location, from);
    player->money += std::rand()%99 + 1;
};

bool GoldBag::canActivate(Tile& tile, Character* c)
{
    player = (Player*) c;
    return Skill::canActivate(tile, c);
};

GoldBag* GoldBag::copy()
{
    return new GoldBag(0,0,state);
};