#pragma once

#include "../Skills/Database.hpp"
#include "../Entities/Player.hpp"
#include<cstdlib>
#include<ctime>

class Shop
{
private:
    Player* player;
    std::vector<Skill*> skills;
    std::pair<Skill*, int> stock[8];
    double price[8];
    std::vector<sf::Vector2f> positions;
    sf::Texture texture;
    sf::Sprite slot;
    sf::Font font;
    sf::Text text;

    int amount;

public:
    Shop(/* args */);
    ~Shop();
    void render(sf::RenderWindow*);
    void enter(Player* p);
    void reset();
    void handleEvents(Hitbox, bool&);
};
