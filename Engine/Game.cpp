#include "Game.hpp"

Game::Game() :
test(500, 200, 100, 100),
testB(110, 230, 100, 40),
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

    handler.addToken(&player);
    //handler.addToken(new Swat(500, 750));
    handler.addToken(new Bazooka(100, 200, 0, true));

    playerCooldowns["Bazooka"]  = {0, 40};
    playerCooldowns["Firewall"] = {0,0};

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
                mousePressed = !player.getInv().handle(player.mousePosition());
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

                    if(playerCooldowns[skill->namae()].first <= 0)
                    {
                        playerCooldowns[skill->namae()].first = playerCooldowns[skill->namae()].second;

                        Skill* other = skill->copy();
                        Tile& tile = map.getSelected();

                        if(other->canActivate(tile, &player))
                        {
                            other->activate(tile, sf::Vector2f(player.getHB().getX(), player.getHB().getY()));
                            player.useSkill();
                            handler.addToken(other);
                        }
                        handler.removeToken(skill);
                    }
                }
            }

            for(auto& pair: playerCooldowns)
            {
                pair.second.first -= DeltaTime::get();
            }
            handler.handleAI(&player);
            
            handler.render(graphics);
            
            ui.render(graphics, player);
            
            handler.update();
            std::vector<Enemy*> wave = spawner.spawn(&map, handler.hasEnemies());
            for(Enemy* e: wave)
            {
                TokenHandler::addToken(e);
            }
            
            DeltaTime::tick();

            if(player.dead()) return;
        }

        graphics->display();
    } 
};