#pragma once

#include "../Entities/Player.hpp"
#include "../Entities/Enemy.hpp"
#include "../Skills/Skill.hpp"
#include <vector>
#include<algorithm>
#include<iterator>

class TokenHandler
{
private:
    static std::vector<Token*> tokens;
    static std::vector<Token*> add;
    static std::vector<Token*> rubbish;
    static std::vector<Enemy*> AI;
    bool enemies;

public:
    TokenHandler();
    ~TokenHandler();
    void update();
    void render(sf::RenderWindow*);
    static void addToken(Token*);
    static void removeToken(Token*);
    static void move(Character*);
    static std::vector<Token*> getRubbish();
    static bool intialiseMap(Hitbox);
    static void handleAI(Player*);
    bool hasEnemies();
    
private:
    static std::vector<Token*> getCollisions(Character*);
    void insertionSort();
    void _switch(int i, int j);
    static bool contains(std::vector<Token*>, Token*);

};
