#include "Game.hpp"

Game::Game() :
test(500, 200, 100, 100),
testB(110, 230, 100, 40),
player()
{
    HEIGHT = 800;
    WIDTH  = 800;
    this->graphics = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "GAME");
    currState = MENU;
    handler.addToken(&test);
    handler.addToken(&testB);

    map.load(sf::Vector2f(800, 800));
    mousePressed = false;

    //handler.addToken(new Bazooka(100, 200, 0, true));

    playerCooldowns["Bazooka"]  = {0, 40};
    playerCooldowns["Firewall"] = {0,0};

    user = new Player(1, "Name");
    player = user;

};

Game::~Game(){};

void Game::run()
{
    while (graphics->isOpen())
    {
        if(player == nullptr) player = user;

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
                mousePressed = !player->getInv().handle(player->mousePosition());
            }
            
            player->handleEvents(event, graphics);
            
            menu.handleEvents(event);
        }
        graphics->clear();

        if(currState == MENU)
        {
            int out = menu.render(graphics, player->mousePosition(), mousePressed);
            if(out == 1)
            {
                player = menu.getUser();
                currState = GAME;
                mousePressed = false;
                handler.addToken(player);
            }
            else if( out == 2)
            {
                break;
            }
        }
        else if(currState == GAME)
        {
            map.render(graphics, player->mousePosition());
            if(mousePressed)
            {
                Skill* skill = player->getSelected();

                if(skill != nullptr)
                {

                    if(playerCooldowns[skill->namae()].first <= 0)
                    {
                        playerCooldowns[skill->namae()].first = playerCooldowns[skill->namae()].second;

                        Skill* other = skill->copy();
                        Tile& tile = map.getSelected();

                        if(other->canActivate(tile, player))
                        {
                            other->activate(tile, sf::Vector2f(player->getHB().getX(), player->getHB().getY()));
                            player->useSkill();
                            handler.addToken(other);
                        }
                    }
                    if(!player->getInv().contains(skill))
                        handler.removeToken(skill);
                }

            }

            for(auto& pair: playerCooldowns)
            {
                pair.second.first -= DeltaTime::get();
            }

            handler.handleAI(player);
            handler.render(graphics);
            ui.render(graphics, *player);
            handler.update();
            
            std::vector<Enemy*> wave = spawner.spawn(&map, handler.hasEnemies());
            for(Enemy* e: wave)
            {
                TokenHandler::addToken(e);
            }

            if(player->dead())
            {
                mousePressed = false;
                currState = MENU;
                player->setMaxWave(spawner.currWave());
                menu.kill(player);
                player = user;
            }
        }
        DeltaTime::tick();
        graphics->display();
    }
    menu.save();
};