#include "Shop.hpp"

Shop::Shop(/* args */)
{
    texture.loadFromFile("Art/Slot.png");
    slot.setTexture(texture);
    slot.scale(4,4);
    font.loadFromFile("Art/BadComic-Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(16);

    positions.push_back(sf::Vector2f(300, 180));
    positions.push_back(sf::Vector2f(420, 180));
    positions.push_back(sf::Vector2f(500, 180));
    positions.push_back(sf::Vector2f(320, 300));
    positions.push_back(sf::Vector2f(440, 300));
    positions.push_back(sf::Vector2f(620, 300));
    positions.push_back(sf::Vector2f(320, 440));
    positions.push_back(sf::Vector2f(400, 440));

    std::srand(std::time(NULL));
}

Shop::~Shop()
{
}

void Shop::render(sf::RenderWindow* g)
{
    text.setString("Your Items:");
    text.setPosition(20, 180);
    g->draw(text);
    for(int i = 0; i < player->getInv().getSize(); i++)
    {
        double x = 20 + 40*(i%3);
        double y = 200 + (i%5)*40;
        slot.setPosition(x, y);
        g->draw(slot);
        if(i < skills.size() && skills[i] != NULL)
        {
            sf::Sprite icon = skills[i]->getIcon();
            icon.setPosition(x+4, y+4);
            g->draw(icon);
        }
    }
    for(sf::Vector2f pos: positions)
    {
        slot.setPosition(pos.x, pos.y);
        g->draw(slot);
    }
    for(int i = 0; i < 8; i++)
    {
        if(stock[i].first != NULL)
        {
            sf::Sprite icon = stock[i].first->getIcon();
            icon.setPosition(positions[i].x+4, positions[i].y+4);
            g->draw(icon);
            text.setString(std::to_string(stock[i].second));
            text.setPosition(positions[i].x+2, positions[i].y+2);
            g->draw(text);
        }
    }
};

void Shop::enter(Player* p)
{
    this->player = p;
    skills = p->getInv().getInventory();
};

void Shop::reset()
{
    std::cout<<"START"<<std::endl;
    for(int i = 0; i < 8; i++) 
    {
        stock[i] = {NULL, 0};
        price[i] = 0;
    }
    amount = std::rand()%8;
    std::vector<double> indexes = {0,1,2,3,4,5,6,7};
    for(int i = 0; i < amount; i++)
    {
        int rnd = std::rand()%indexes.size();
        int index = indexes[rnd];
        stock[index] = std::pair<Skill*, int>{Database::getRandom(), std::rand()%10+1};
        price[index] = std::rand()%100;
        indexes.erase(indexes.begin() + rnd);
    }
    std::cout<<"END"<<std::endl;
}

void Shop::handleEvents(Hitbox m, bool& isPressed)
{
    for(int i = 0; i < 8; i++)
    {
        if(stock[i].first != NULL && isPressed)
        {
            if(m.intersects(Hitbox(positions[i].x, positions[i].y,40,40)) && player->money >= price[i])
            {
                stock[i].second--;
                player->money -= price[i];
                player->getInv().add(stock[i].first);
                if(stock[i].second <= 0) stock[i] = {NULL, 0};
                isPressed = false;
            }
        }
    }
}