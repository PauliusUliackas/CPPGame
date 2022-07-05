#pragma once

#include "./Entities/Token.hpp"

class Drop : public Token
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Drop(std::string icon);
    ~Drop();
    void render(sf::RenderWindow*);
    void place(double, double);
};

