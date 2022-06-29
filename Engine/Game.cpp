#include "Game.hpp"

Game::Game() :
test(10, 10, 100, 100),
test2(500, 50, 100, 40)
{
    HEIGHT = 800;
    WIDTH  = 800;
    this->graphics = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "GAME");
    currState = GAME;
    handler.addToken(&test);
    handler.addToken(&test2);
};

Game::~Game(){};

void Game::run()
{
    while (graphics->isOpen())
    {
        sf::Event event;
        while (graphics->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                graphics->close();
        }

        graphics->clear();

        if(currState == MENU)
        {

        }
        else if(currState == GAME)
        {
            handler.render(graphics);
            handler.update();
            DeltaTime::tick();
        }

        graphics->display();
    } 
};