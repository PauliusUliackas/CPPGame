#pragma once

#include "../Skills/Firewall.hpp"
#include <iostream>
#include <vector>

class Inventory
{
    private:
        std::vector<Skill*> items;
        std::vector<double> amount;
        unsigned int selected;

    public:
        Inventory();
        ~Inventory();
        void add(Skill*, double = 1);
        void remove(Skill*);
        void _switch(Skill*, Skill*);
        void render(sf::RenderWindow*);
        void select(int);
        Skill* getSelected();
        void print();
};