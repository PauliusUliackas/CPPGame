#include "Game.hpp"

Game::Game():
exitPoint(600, 200, "Exit", 16, 5),
shop(600, 600, "ShopBuilding", 16, 5, "ShopButton")
{
    std::srand(std::time(NULL));
    HEIGHT = 800;
    WIDTH  = 800;
    this->graphics = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "One More");
    currState = MENU;
    mousePressed = false;
    Database::loadCooldowns(playerCooldowns);
    user = new Player(1, {},{}, 0, "Name");
    player = user;
    exitPoint.setLabel("Leave Match");
    shop.setLabel("Reset Shop");
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
                handler.reset();
                spawner = Spawner();
                player = menu.getUser();
                currState = GAME;
                mousePressed = false;
                handler.addToken(player);
                handler.addToken(&exitPoint);
                handler.addToken(&shop);
                map.load(sf::Vector2f(800, 800));
                shopReset = false;
            }
            else if( out == 2)
            {
                break;
            }
        }
        else if(currState == GAME)
        {
            map.render(graphics, player->mousePosition());
            if(!handler.hasEnemies())
            {
                if(exitPoint.handleEvents(graphics, player->mousePosition(), mousePressed, player->getHB()))
                {
                    mousePressed = false;
                    currState = MENU;
                    player->setMaxWave(spawner.currWave());
                    player->setX(500);
                    player->setY(500);
                }
            }
            if(!shopReset && spawner.currWave() >= 5 && shop.handleEvents(graphics, player->mousePosition(), mousePressed, player->getHB()))
            {
                mousePressed = false;
                menu.resetShop();
                shopReset = true;
            }
            if(mousePressed)
            {
                Skill* skill = player->getSelected();

                if(skill != nullptr)
                {

                    if(playerCooldowns[skill->namae()].first <= 0)
                    {
                        playerCooldowns[skill->namae()].first = playerCooldowns[skill->namae()].second - (playerCooldowns[skill->namae()].second * player->getStat("Cooldown"))/100;

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