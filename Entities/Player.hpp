#pragma once

#include "Character.hpp"
#include "../Skills/Database.hpp"
#include "../DataStructures/Inventory.hpp"
#include "unordered_map"
#include "../Engine/PlayerStats.hpp"

class Player : public Character
{
private:
    std::vector<bool> keys;
    Hitbox mousePos;
    sf::Vector2f windowSize;
    Inventory inv;
    Hitbox redHealth;
    Hitbox greenHealth;
    float UIdelay;
    double speed;
    std::string name;

    int maxWave;
    PlayerStats stats;

public:
    int money;

public:
    Player(int health, std::vector<std::string> data, std::vector<std::string> stats, int money, std::string name = "");
    ~Player();
    void render(sf::RenderWindow*);
    void update();
    void handleEvents(sf::Event, sf::RenderWindow*);
    Hitbox mousePosition();
    Skill* getSelected();
    void useSkill();
    void handleCollisions();
    Inventory& getInv();
    void handleUI(sf::RenderWindow*);

    std::string getName();

    Player& operator=(const Player&);

    std::string save();

    void setMaxWave(int);
    void dealDamage(int);
    void increaseStat(std::string name, int i = 1);

    double getStat(std::string name);
    PlayerStats& getStats();

private:
    void handleAnimations();
    void loadInventory(std::vector<std::string>);

};