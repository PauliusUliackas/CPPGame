#pragma once

#include "Character.hpp"
#include "../Skills/Firewall.hpp"
#include "../DataStructures/Inventory.hpp"
#include "unordered_map"

class Player : public Character
{
private:
    std::vector<bool> keys;
    double speed;
    Hitbox mousePos;
    sf::Vector2f windowSize;
    Inventory inv;
    Hitbox redHealth;
    Hitbox greenHealth;
    float UIdelay;

public:
    Player(double, double, double, double);
    ~Player();
    void render(sf::RenderWindow*);
    void update();
    void handleEvents(sf::Event, sf::RenderWindow*);
    Hitbox mousePosition();
    Skill* getSelected();
    void useSkill();

private:
    void handleAnimations();
    void handleCollisions();
    void handleUI(sf::RenderWindow*);

};