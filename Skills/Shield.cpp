#include "Shield.hpp"

Shield::Shield(double x, double y, int state) : Skill("Shield", x, y, state)
{
    length = 28;
    curr = 0;
    texture.loadFromFile("Art/ShieldIcon.png");
    icon.setTexture(texture);
    icon.scale(4,4);
    anime.load("Shield", "Shield", 25);
    anime.scale("Shield", 2, 2);
    anime.select("Shield");
    isPicked = false;
    rarity = 2;
    obj = true;
};

Shield::~Shield()
{
    activeOn->setOccupied(false);
};

void Shield::render(sf::RenderWindow* g)
{
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

void Shield::activate(Tile& location, sf::Vector2f from)
{
    Skill::activate(location, from);
    hitbox = location.getTile();
    activeOn = &location;
    activeOn->setOccupied(true);
};

bool Shield::canActivate(Tile& tile, Character* c)
{
    double length = 500;
    double x1 = c->getHB().getX();
    double y1 = c->getHB().getY();
    double x2 = tile.getHitbox().getX();
    double y2 = tile.getHitbox().getY();
    double magnitude = std::sqrt(std::pow(x2-x1,2) + std::pow(y2-y1,2));
    if(magnitude > 400 && magnitude < 41) return false;
    return Skill::canActivate(tile, c) && !tile.isOccupied();
};

Shield* Shield::copy()
{
    return new Shield(getHB().getX(), getHB().getY(), state);
};

bool Shield::isOver()
{
    curr += DeltaTime::get();
    return (Skill::isOver() && curr >= length);
};