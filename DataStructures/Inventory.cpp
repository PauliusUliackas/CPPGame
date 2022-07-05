#include "Inventory.hpp"

Inventory::Inventory()
{
    selected = 0;
    texture.loadFromFile("Art/Slot.png");
    slot.setTexture(texture);
    slot.scale(4,4);
    font.loadFromFile("Art/BadComic-Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(16);

    txt.loadFromFile("Art/Slot1.png");
    slt1.setTexture(txt);
    slt1.scale(4,4);

    switchOne = -1;

    for(int i = 0; i < size; i++)
    {
        amount[i] = 0;
        items[i] = NULL;
    }

};

Inventory::~Inventory(){};

void Inventory::add(Skill* skill, int x)
{
    for(int i = 0; i < size; i++)
    {
        if(items[i] == NULL) continue;

        if(items[i]->equals(skill))
        {
            skill->isPicked = true;
            amount[i]+=x;
            return;
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(items[i] == NULL)
        {
            items[i] = skill;
            amount[i] = x;
            return;
        }
    }
};

void Inventory::remove(Skill* skill)
{
    for(int i = 0; i < size; i++)
    {
        if(items[i] == NULL) continue;

        if(items[i]->equals(skill))
        {
            amount[i]--;
            if(amount[i] < 1)
            {
                items[i] = NULL;
                amount[i] = 0;
            }
            return;
        }
    }
};

void Inventory::_switch(int index1, int index2)
{
        int tempAmount = amount[index2];
        Skill* tempSkill = items[index2];

        amount[index2] = amount[index1];
        items[index2] = items[index1];

        amount[index1] = tempAmount;
        items[index1] = tempSkill;
};

void Inventory::select(int i)
{
    selected = i;
};

Skill* Inventory::getSelected()
{
    if(size == 0) 
    {
        return nullptr;
    }
    return items[selected];
};

void Inventory::print()
{
    for(int i = 0; i< size; i++)
    {
        std::cout<<items[i]->namae()<<" "<<amount[i]<<std::endl;
    }
};

void Inventory::render(sf::RenderWindow* g)
{
    for(int i = 0; i< 9; i++)
    {
        sf::Sprite frame = slot;
        if(i == selected) frame = slt1;
        frame.setPosition(220+slot.getGlobalBounds().width*i, 750);
        g->draw(frame);
        if(items[i] != NULL)
        {
            sf::Sprite icon = items[i]->getIcon();
            icon.setPosition(224+slot.getGlobalBounds().width*i, 754);
            text.setString(std::to_string(amount[i]));
            text.setPosition(224+slot.getGlobalBounds().width*i,750);
            g->draw(icon);
            g->draw(text);
        }
    }
};

bool Inventory::handle(Hitbox mouse)
{
    
    for(int i = 0; i< 9; i++)
    {
        bool intersects = mouse.intersects(Hitbox(220+slot.getGlobalBounds().width*i, 750, slot.getGlobalBounds().width, slot.getGlobalBounds().height));
        
        if(intersects && items[i] != NULL && switchOne < 0) switchOne = i;
        else if(intersects && switchOne >= 0)
        {
            _switch(switchOne, i);
            switchOne = -1;
        }

        if(intersects) return true;
    }
    return false;

};