#pragma once

#include "../Entities/Character.hpp"
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

public:
    TokenHandler();
    ~TokenHandler();
    void update();
    void render(sf::RenderWindow*);
    static void addToken(Token*);
    static void removeToken(Token*);
    static void move(Character*);
    static std::vector<Token*> getRubbish();
    
private:
    static std::vector<Token*> getCollisions(Character*);

};
