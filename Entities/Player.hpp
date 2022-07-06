#pragma once

#include "Character.hpp"
#include "../Skills/Firewall.hpp"
#include "../Skills/Bazooka.hpp"
#include "../DataStructures/Inventory.hpp"
#include "unordered_map"

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

public:
    Player(int health, std::string name = "");
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

private:
    void handleAnimations();

};