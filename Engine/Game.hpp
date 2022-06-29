#pragma once

#include <SFML/Graphics.hpp>

class Game
{
    private:
        sf::RenderWindow* graphics;
        double HEIGHT, WIDTH;
        enum STATE
        {
            MENU,
            GAME
        };
        STATE currState;

    public:
        Game();
        ~Game();
        void run();

};