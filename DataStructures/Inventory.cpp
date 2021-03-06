#include "Inventory.hpp"

Inventory::Inventory()
{
    selected = 0;
    texture.loadFromFile("Art/Slot.png");
    backpack.loadFromFile("Art/Backpack.png");
    slot.setTexture(texture);
    slot.scale(4,4);
    font.loadFromFile("Art/BadComic-Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(16);

    txt.loadFromFile("Art/Slot1.png");
    slt1.setTexture(txt);
    slt1.scale(4,4);

    switchOne = -1;

    bp.setTexture(backpack);
    bp.scale(4,4);
    bp.setPosition(220+slot.getGlobalBounds().width*9, 750);

    for(int i = 0; i < size; i++)
    {
        amount[i] = 0;
        items[i] = NULL;
    }

    extraInventory = false;

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

    if(extraInventory)
    {
        for(int i = 9; i< size; i++)
        {
            sf::Sprite frame = slot;
            if(i == selected) frame = slt1;
            frame.setPosition(220+frame.getGlobalBounds().width*(i-9), 700);
            g->draw(frame);
            if(items[i] != NULL)
            {
                sf::Sprite icon = items[i]->getIcon();
                icon.setPosition(224+slot.getGlobalBounds().width*(i-9), 704);
                text.setString(std::to_string(amount[i]));
                text.setPosition(224+slot.getGlobalBounds().width*(i-9),700);
                g->draw(icon);
                g->draw(text);
            }
        }
    }
    else
    {
        Skill* item = getSelected();
        if(item != nullptr)
        {
            text.setString(item->namae());
            text.setPosition(224+slot.getGlobalBounds().width*4, 730);
            g->draw(text);
        }
    }

    g->draw(bp);

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

    if(mouse.intersects(Hitbox(220+slot.getGlobalBounds().width*9, 750, slot.getGlobalBounds().width, slot.getGlobalBounds().height)))
    {
        extraInventory = !extraInventory;
        return true;
    }

    for(int i = 9; i< size; i++)
    {
        bool intersects = mouse.intersects(Hitbox(220+slot.getGlobalBounds().width*(i-9), 700, slot.getGlobalBounds().width, slot.getGlobalBounds().height));
        
        if(intersects && items[i] != NULL && switchOne < 0) switchOne = i;
        else if(intersects && switchOne >= 0)
        {
            _switch(switchOne, i);
            switchOne = -1;
        }
    }

    return extraInventory;

};

bool Inventory::contains(Skill* s)
{
    for(int i = 0; i < size; i++)
    {
        if(items[i] == s) return true;
    }
    return false;
};

std::string Inventory::save()
{
    std::string out = "";
    for(int i = 0; i < size; i++)
    {
        if(items[i] == NULL) continue;
        out += items[i]->namae() + "," + std::to_string(amount[i]) + ",";
    }
    return out;
};

std::vector<Skill*> Inventory::getInventory()
{
    std::vector<Skill*> out;
    for(Skill* skill: items)
    {
        if(skill != NULL) out.push_back(skill);
    }
    return out;
};

int Inventory::getSize() const
{
    return size;
}