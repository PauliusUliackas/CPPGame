#include "ExitPoint.hpp"

ExitPoint::ExitPoint(double x, double y, std::string name, double width, int scale, std::string buttonName) : Building(x, y, name, width, scale),
exit(700, 450, buttonName),
extra(x-10, y-10, (width*scale)+20, (width*scale)+20)
{
}

ExitPoint::~ExitPoint()
{
}

bool ExitPoint::handleEvents(sf::RenderWindow* g, Hitbox hb, bool& isPressed, Hitbox player)
{
    if(player.intersects(extra) && exit.render(g, hb, isPressed))
    {
        return true;
    }
    return false;
};

void ExitPoint::setLabel(std::string l)
{
    exit.setLabel(l);
}