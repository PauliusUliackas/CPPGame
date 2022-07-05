#pragma once

#include "TokenHandler.hpp"
#include "../Entities/Player.hpp"
#include "../Map/Map.hpp"
#include "../UI/UI.hpp"
#include "Spawner.hpp"

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
        Token test;
        Token testB;
        Map map;
        bool mousePressed;
        UI ui;
        Spawner spawner;

        std::unordered_map<std::string, std::pair<double,double>> playerCooldowns;
        
    public:
        Game();
        ~Game();
        void run();

};