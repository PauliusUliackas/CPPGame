#pragma once

#include "../Skills/Firewall.hpp"
#include "../Skills/Bazooka.hpp"
#include <iostream>
#include <vector>

class Inventory
{
    private:
        const int size = 15;
        Skill* items[15];
        int amount[15];
        unsigned int selected;
        sf::Texture texture, txt;
        sf::Sprite slot, slt1;
        sf::Font font;
        sf::Text text;

    public:
        Inventory();
        ~Inventory();
        void add(Skill*, int = 1);
        void remove(Skill*);
        void _switch(Skill*, Skill*);
        void render(sf::RenderWindow*);
        void select(int);
        Skill* getSelected();
        void print();
};