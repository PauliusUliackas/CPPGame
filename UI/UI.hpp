#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Player.hpp"

class UI
{
private:
    /* data */
public:
    UI(/* args */);
    ~UI();
    void render(sf::RenderWindow*, Player p);
    
};
