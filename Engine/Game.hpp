#pragma once

#include "TokenHandler.hpp"

class Game
{
    private:
        sf::RenderWindow* graphics;
        TokenHandler handler;
        double HEIGHT, WIDTH;
        enum STATE
        {
            MENU,
            GAME
        };
        STATE currState;
        Token test;
        Token test2;

    public:
        Game();
        ~Game();
        void run();

};