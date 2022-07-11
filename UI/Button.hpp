#pragma once

#include <SFML/Graphics.hpp>
#include "../DataStructures/Hitbox.hpp"

class Button
{
private:
    
    sf::Texture txt;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text text;
    Hitbox hb;

public:
    Button(double x, double y, std::string name, int scale = 4);
    ~Button();
    bool render(sf::RenderWindow*, Hitbox mouse, bool isPressed);
    void scale(double x);
    void setLabel(std::string);
};
