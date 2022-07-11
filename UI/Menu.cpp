#include "Menu.hpp"

Menu::Menu() :
play(350, 200, "PlayButton"),
exit(350, 600, "ExitButton"),
leaderboard(550, 400, "LeaderboardButton"),
choose(150, 400, "PistolButton"),
add(350, 500, "AddButton"),
shopB(350, 400, "ShopButton")
{
    f.loadFromFile("Art/BadComic-Regular.ttf");
    text.setFont(f);
    text.setCharacterSize(16);

    state = 0;

    maxSize = 20;

    user = nullptr;

    std::fstream file;
    file.open("Saves/Characters.txt", std::ios::in);
    if (file.is_open())
    {
      std::string line;
      while(std::getline(file, line))
      {
          std::vector<std::string> list = split(line, ' ');
          Player* temp = new Player(std::stoi(list[1]), split(list[3], ','), std::stoi(list[4]), list[0]);
          temp->setMaxWave(std::stoi(list[2]));
          users.push_back(temp);
      }
      file.close();
    }

}

Menu::~Menu()
{
    shop.save();
}


int Menu::render(sf::RenderWindow* g, Hitbox mouse, bool& isPressed)
{
    if(state == 0)
    {
        if(users.size() == 0)
        {
            text.setString("Please Create a user first by clicking on a pistol");
            text.setPosition(220, 200);
            g->draw(text);
        }
        else if(user == nullptr)
        {
            text.setString("Please Select a Character To Play As");
            text.setPosition(220, 200);
            g->draw(text);
        }
        else if(play.render(g, mouse, isPressed)) return 1;
        if(exit.render(g, mouse, isPressed)) return 2;
        if(leaderboard.render(g, mouse, isPressed)) state = 3;
        if(choose.render(g, mouse, isPressed)) state = 1;
        if(user != nullptr && shopB.render(g, mouse, isPressed))
        {
            isPressed = false;
            state = 4;
            shop.enter(user);
        }
    }
    if(state == 1)
    {

        for(int i = 0; i < users.size(); i++)
        {
            text.setString(users[i]->getName());
            text.setPosition(350, 50+20*i);
            g->draw(text);
            Button del(500, 50+20*i, "DeleteButton", 1);
            if(del.render(g, mouse, isPressed))
            {
                if(user == users[i]) user = nullptr;
                isPressed = false;
                remove(i);
            }
            Button sel(550, 50+20*i, "Select", 1);
            if(sel.render(g, mouse, isPressed))
            {
                user = users[i];
                isPressed = false;
            }
        }

        if(exit.render(g, mouse, isPressed))
        {
            isPressed = false;
            state = 0;
        }

        if(add.render(g, mouse, isPressed))
        {
            state = 2;
            isPressed = false;
            name = "";
        }
    }
    if(state == 2)
    {

        if(exit.render(g, mouse, isPressed))
        {
            isPressed = false;
            state = 1;
        }
        if (users.size() >= 20)
        {
            text.setString("Maximum amount of users is 20");
            text.setPosition(280, 500);
            g->draw(text);
        }
        else if(add.render(g, mouse, isPressed))
        {
            if(name.size() > 0)
            {
                state = 1;
                
                user = new Player(100, {"Firewall", "10", "Bazooka", "10"}, 0, name);
                users.push_back(user);

                name = "";
                isPressed = false;
                std::cout<<user->save()<<std::endl;
            }
        }
        text.setString("Please type new Character's name:");
        text.setPosition(80, 200);
        g->draw(text);
        text.setString(name);
        text.setPosition(350, 200);
        g->draw(text);
    }

    if(state == 3)
    {
        if(exit.render(g, mouse, isPressed))
        {
            isPressed = false;
            state = 0;
        }

        std::fstream file;
        file.open("Saves/Leaderboard.txt", std::ios::in);

        if (file.is_open())
        {
            std::string line;
            int i = 0;
            while(std::getline(file, line))
            {
                std::vector<std::string> list = split(line, ' ');
                text.setString(std::to_string(i+1) + ". " + list[0] + " Survived For: " + list[1]);
                text.setPosition(280, 200+20*i);
                g->draw(text);
                i++;
            }
            file.close();
        }

    }
    if(state == 4)
    {
        if(exit.render(g, mouse, isPressed))
        {
            isPressed = false;
            state = 0;
        }
        
        shop.handleEvents(mouse, isPressed);
        shop.render(g);

        text.setString("20$");
        text.setPosition(300,530);
        g->draw(text);

        if(add.render(g, mouse, isPressed) && user->money >= 20)
        {
            user->dealDamage(-5);
            user->money -= 20;
            isPressed = false;
        }

        text.setString("Money: " + std::to_string(user->money));
        text.setPosition(700, 20);
        g->draw(text);
    }

    if(user != nullptr)
    {
        text.setString("Playing As: " + user->getName());
        text.setPosition(10, 10);
        g->draw(text);
    }

    return 0;
};

void Menu::handleEvents(sf::Event e)
{
    if(state == 2)
    {
        if(e.type == sf::Event::TextEntered)
        {
            if(e.text.unicode == 8) // Delete
            {
                name = name.substr(0, name.size() -1);
            }
            else if(name.size() < maxSize) name += e.text.unicode;
        }
    }
}

Player* Menu::getUser()
{
    return user;
}

std::vector<std::string> Menu::split(std::string string, char by)
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

void Menu::save()
{
    std::fstream file;
    file.open("Saves/Characters.txt",std::ios::out);  // open a file to perform write operation using file object
    if(file.is_open())     //checking whether the file is open
    {
        for(Player* player: users)
        {
            file<<player->save()<<std::endl;
        }
    }
    file.close();

};

void Menu::remove(int i)
{
    std::fstream file;
    file.open("Saves/Leaderboard.txt", std::ios::in);

    std::map<double, std::string> leaderboard;

    if (file.is_open())
    {
      std::string line;
      while(std::getline(file, line))
      {
          if(line == "") continue;
          std::vector<std::string> list = split(line, ' ');
          leaderboard[std::stoi(list[1])] = list[0];
      }
      file.close();
    }

    std::string playerData = users[i]->save();
    int record = std::stoi(split(playerData, ' ')[2]);
    leaderboard[record] = users[i]->getName();

    file.open("Saves/Leaderboard.txt",std::ios::out);  // open a file to perform write operation using file object
    if(file.is_open())     //checking whether the file is open
    {
        int i = 0;
        for(auto pair = leaderboard.rbegin(); pair != leaderboard.rend(); pair++)
        {
            file<<pair->second<<" "<<pair->first<<std::endl;
            i++;
            if(i == 5) break;
        }
    }
    file.close();
    delete users[i];
    users.erase(users.begin() + i);
};

void Menu::kill(Player* player)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i] == player)
        {
            remove(i);
        }
    }
    user = nullptr;
};

void Menu::resetShop()
{
    shop.reset();
}