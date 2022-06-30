#pragma once

#include "../DataStructures/DeltaTime.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Hitbox
{
    private:
        double radius, x, y;
        sf::RectangleShape hitbox;

    public:
        Hitbox(double, double, double, double);
        ~Hitbox();

        void render(sf::RenderWindow*, sf::Color = sf::Color::Green);
        
        double getX();
        double getY();
        double getHeight();
        double getWidth();

        bool intersects(Hitbox);
        bool intersects(double, double, double, double);

        void moveBy(double, double);
        void setX(double);
        void setY(double);

};