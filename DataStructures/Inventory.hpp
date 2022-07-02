#pragma once

#include "../Skills/Firewall.hpp"
#include <iostream>
#include <vector>

class Inventory
{
    private:
        std::vector<Skill*> items;
        std::vector<int> amount;
        unsigned int selected;
        sf::Texture texture;
        sf::Sprite slot;
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