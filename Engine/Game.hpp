#pragma once

#include "TokenHandler.hpp"
#include "../Entities/Player.hpp"
#include "../Map/Map.hpp"
#include "../UI/UI.hpp"

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
        Player player;
        Character test;
        Token testB;
        Map map;
        bool mousePressed;
        
    public:
        Game();
        ~Game();
        void run();

};