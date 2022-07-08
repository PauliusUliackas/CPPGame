#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Character.hpp"
#include <string>
#include "../Map/Tile.hpp"
#include <cmath>

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
    Animation anime;
    std::vector<Token*> collisions;
    int rarity;

public:
    bool isPicked;

public:
    Skill(std::string name, double x, double y, int state);
    virtual ~Skill();
    virtual void render(sf::RenderWindow*);
    virtual void update();
    virtual void activate(Tile& location, sf::Vector2f from);
    virtual bool canActivate(Tile& tile, Character* c);
    bool equals(Skill*);
    virtual Skill* copy();
    virtual bool isOver();
    void setOver();
    void pickUp();
    bool canPickUp();
    bool isActive();

    void addCollision(Token*);

    virtual sf::Sprite getIcon();

    std::string namae();
    void setActive();

    double magnitude(sf::Vector2f vec);
    sf::Vector2f sub(sf::Vector2f vec1,sf::Vector2f vec2);
    sf::Vector2f add(sf::Vector2f vec1,sf::Vector2f vec2);
    sf::Vector2f mult(sf::Vector2f vec1,double vec2);
    sf::Vector2f div(sf::Vector2f vec1,double vec2);
    sf::Vector2f normalise(sf::Vector2f vec);

    int generatePrice();
    
};
