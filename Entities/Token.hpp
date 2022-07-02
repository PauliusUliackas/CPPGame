#pragma once

#include "../DataStructures/Hitbox.hpp"
#include "../Animation/Animation.hpp"

class Token
{

    protected:
        Hitbox hitbox;
        bool solid;
        Animation anime;
    
    public:
        Token(double, double, double, double);
        virtual ~Token();
        virtual void render(sf::RenderWindow*);
        virtual void update();
        void moveBy(double, double);
        virtual bool operator==(const Token*);
        virtual bool operator<(const Token*);
        bool isSolid();
        bool collides(Token*);
        void setX(double);
        void setY(double);
        void leftOf(Token*);
        void rightOf(Token*);
        void topOf(Token*);
        void bottomOf(Token*);
        Hitbox getHB();

};