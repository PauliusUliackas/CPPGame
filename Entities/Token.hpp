#pragma once

#include "../DataStructures/Hitbox.hpp"

class Token
{

    protected:
        Hitbox hitbox;
        bool solid;
    
    public:
        Token(double, double, double, double);
        ~Token();
        virtual void render(sf::RenderWindow*);
        virtual void update();
        void moveBy(double, double);
        bool operator==(const Token*);
        bool operator<(Token&);
        bool isSolid();
        bool collides(Token*);
        void setX(double);
        void setY(double);
        void leftOf(Token*);
        void rightOf(Token*);
        void topOf(Token*);
        void bottomOf(Token*);

};