#include "Shop.hpp"

Shop::Shop()
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

    std::fstream file;
    file.open("Saves/Shop.txt", std::ios::in);
    if (file.is_open())
    {
      std::string line;
      int i = 0;
      while(std::getline(file, line))
      {
          std::vector<std::string> list = split(line, ' ');
          if(list.size() == 3)
          {
                stock[i].first = Database::getByName(list[0]);
                stock[i].second = std::stoi(list[1]);
                price[i] = std::stoi(list[2]);
          }
          i++;
      }
      file.close();
    }
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
            text.setPosition(positions[i].x-16, positions[i].y-16);
            g->draw(text);
            text.setString(std::to_string(price[i]) + "$");
            text.setPosition(positions[i].x+5, positions[i].y+40);
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
        price[index] = stock[index].first->generatePrice();
        indexes.erase(indexes.begin() + rnd);
    }
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

void Shop::save()
{
    std::fstream file;
    file.open("Saves/Shop.txt",std::ios::out);  // open a file to perform write operation using file object
    if(file.is_open())     //checking whether the file is open
    {
        for(int i = 0; i < 8; i++)
        {
            if(stock[i].first != NULL)
                file<<stock[i].first->namae()<<" "<<stock[i].second<<" "<<price[i];
            file<<std::endl;
        }
    }
    file.close();
};

std::vector<std::string> Shop::split(std::string string, char by)
{
    std::vector<std::string> out;
    std::string current = "";
    for(int i = 0; string[i] != '\0'; i++)
    {
        char curr = string[i];
        if(curr == by)
        {
            if(current.length() > 0)
                out.push_back(current);
            current = "";
        }
        else
            current += curr;

    }
    out.push_back(current);
    return out;
};