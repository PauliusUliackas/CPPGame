#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Player.hpp"

class UI
{
private:
    sf::Text text;
    sf::Font font;
public:
    UI(/* args */);
    ~UI();
    void render(sf::RenderWindow*, Player p);
    
};
