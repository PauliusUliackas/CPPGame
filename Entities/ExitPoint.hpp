#pragma once

#include "Building.hpp"
#include "../UI/Button.hpp"

class ExitPoint : public Building
{
private:
    Button exit;
    Hitbox extra;

public:
    ExitPoint(double x, double y, std::string name, double width, int scale = 1);
    ~ExitPoint();
    bool handleEvents(sf::RenderWindow* g, Hitbox hb, bool& isPressed, Hitbox playerHB);
};
