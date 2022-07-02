#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Token.hpp"
#include <string>
#include "../Map/Tile.hpp"

class Skill : public Token
{

protected:
    enum STATE
        {
            DROP,
            PICKED,
            ACTIVE
        };
    Skill::STATE state;
    sf::Sprite icon;
    sf::Texture texture;
    std::string name;

public:
    Skill(std::string name, double x, double y, int state);
    virtual ~Skill();
    virtual void render(sf::RenderWindow*);
    virtual void activate(Tile& location);
    virtual bool canActivate(Tile& tile);
    bool equals(Skill*);
    virtual Skill* copy();
    virtual bool isOver();
    void pickUp();
    bool canPickUp();

    virtual sf::Sprite getIcon();

    std::string namae();
};
