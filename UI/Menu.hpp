#pragma once

#include "Button.hpp"
#include "../Engine/Shop.hpp"
#include <fstream>
#include <map>

class Menu
{
private:
    Button play, exit, choose, leaderboard, add, shopB;
    sf::Text text;
    sf::Font f;
    std::string name;
    Player* user;

    unsigned int state;
    unsigned int maxSize;

    Shop shop;

    std::vector<Player*> users;

public:
    Menu();
    ~Menu();
    int render(sf::RenderWindow* g, Hitbox mouse, bool& isPressed);
    void handleEvents(sf::Event);
    Player* getUser();
    void save();
    void kill(Player* player);;

private:
    std::vector<std::string> split(std::string, char by);
    void remove(int index);
};