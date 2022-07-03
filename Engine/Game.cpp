#include "Game.hpp"

Game::Game() :
test(500, 200, 100, 100),
testB(510, 230, 100, 40),
player(500, 500, 50, 50)
{
    HEIGHT = 800;
    WIDTH  = 800;
    this->graphics = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "GAME");
    currState = GAME;
    handler.addToken(&test);
    handler.addToken(&testB);

    map.load(sf::Vector2f(800, 800));
    mousePressed = false;

    Tile* t = map.getRandomSpawn();
    handler.addToken(&player);
    handler.addToken(new Swat(t->getHitbox().getX(), t->getHitbox().getY()));
    //handler.addToken(new Swat(500, 750));
    handler.addToken(new Bazooka(100, 200, 0));

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
            
            if (event.type == sf::Event::MouseButtonReleased)
            {
                mousePressed = false;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                mousePressed = true;
            }
            player.handleEvents(event, graphics);
        }

        graphics->clear();

        if(currState == MENU)
        {

        }
        else if(currState == GAME)
        {
            map.render(graphics, player.mousePosition());
            if(mousePressed)
            {
                Skill* skill = player.getSelected();

                if(skill != nullptr)
                {
                    skill = skill->copy();
                    Tile& tile = map.getSelected();

                    if(skill->canActivate(tile, &player))
                    {
                        skill->activate(tile);
                        player.useSkill();
                        handler.addToken(skill);
                    }
                }
            }
            handler.handleAI(&player);
            handler.render(graphics);
            ui.render(graphics, player);
            handler.update();
            DeltaTime::tick();

            if(player.dead()) return;
        }

        graphics->display();
    } 
};