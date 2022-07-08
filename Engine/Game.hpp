#pragma once

#include "TokenHandler.hpp"
#include "../Entities/Player.hpp"
#include "../Map/Map.hpp"
#include "../UI/UI.hpp"
#include "../UI/Menu.hpp"
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
        Player* player;
        Player* user;
        Map map;
        bool mousePressed;
        UI ui;
        Menu menu;
        Spawner spawner;
        ExitPoint exitPoint;

        std::unordered_map<std::string, std::pair<double,double>> playerCooldowns;
        
    public:
        Game();
        ~Game();
        void run();

};