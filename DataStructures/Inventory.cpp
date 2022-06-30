#include "Inventory.hpp"

Inventory::Inventory()
{
    selected = 0;
};

Inventory::~Inventory(){};

void Inventory::add(Skill* skill, double x)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->equals(skill))
        {
            amount[i]+=x;
            return;
        }
    }
    items.push_back(skill);
    amount.push_back(x);
};

void Inventory::remove(Skill* skill)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->equals(skill))
        {
            amount[i]--;
            if(amount[i] < 0)
            {
                items.erase(items.begin() + i);
                amount.erase(amount.begin() + i);
            }
        }
    }
};

void Inventory::_switch(Skill* one, Skill* two)
{
    int index1 = -1;
    int index2 = -1;
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->equals(one))
        {
           index1 = i;
        }
        if(items[i]->equals(two))
        {
            index2 = i;
        }
    }
    if(index1 > -1 && index2 > -1)
    {
        int tempAmount = amount[index2];
        Skill* tempSkill = items[index2];

        amount[index2] = amount[index1];
        items[index2] = items[index1];

        amount[index1] = tempAmount;
        items[index1] = tempSkill;
    }
};

void Inventory::select(int i)
{
    selected = i;
};

Skill* Inventory::getSelected()
{
    if(items.size() == 0) 
    {
        return nullptr;
    }
    return items[selected];
};

void Inventory::print()
{
    for(int i = 0; i< items.size(); i++)
    {
        std::cout<<items[i]->namae()<<" "<<amount[i]<<std::endl;
    }
};