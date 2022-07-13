#include "Player.hpp"

Player::Player(int health, std::vector<std::string> data, std::vector<std::string> stats, int money, std::string name) : Character(500,500,50,50), mousePos(0,0,1,1),
redHealth(10,10,100,40),
greenHealth(10,10,health,40)
{
    keys = {false, false, false, false};
    speed = 5;
    windowSize = sf::Vector2f(800,800);
    loadInventory(data);
    anime.load("WalkingR", "Player", 16);
    anime.select("WalkingL");
    anime.scale("WalkingR", 2, 2);
    anime.flip("WalkingR", "WalkingL", true, false);
    anime.load("WalkingUp", "PlayerUp", 16);
    anime.scale("WalkingUp", 2, 2);
    anime.load("WalkingDown", "PlayerDown", 16);
    anime.scale("WalkingDown", 2, 2);
    anime.resume();
    hitbox.setWidth(35);
    hitbox.setHeight(25);
    UIdelay = 0;
    this->name = name;
    this->health = health;

    if(health > 100) redHealth.setWidth(health);

    maxWave = 0;
    this->money = money;

    this->stats = PlayerStats(stats);
};

Player::~Player()
{
};

void Player::loadInventory(std::vector<std::string> list)
{
    for(int i = 0; i< list.size(); i+=2)
    {
        if(list[i] == "") continue;
        inv.add(Database::getByName(list[i]), std::stoi(list[i+1]));
    }
}

void Player::render(sf::RenderWindow* g)
{
    hitbox.render(g);
    handleAnimations();
    anime.play(g, hitbox.getX(), hitbox.getY()-40);
    handleUI(g);
};

void Player::handleAnimations()
{
    if(velocity.x != 0 || velocity.y != 0) anime.resume();
    else anime.stop();

    if(velocity.x > 0) anime.select("WalkingR");
    else if(velocity.x < 0) anime.select("WalkingL");
    else if(velocity.y < 0) anime.select("WalkingUp");
    else if(velocity.y > 0) anime.select("WalkingDown");
}

void Player::handleUI(sf::RenderWindow* g)
{
    redHealth.render(g, sf::Color::Red);
    if(UIdelay > 2)
    {
        if(health < greenHealth.getWidth())
            greenHealth.setWidth(greenHealth.getWidth()-1);
        else if(health > greenHealth.getWidth())
            greenHealth.setWidth(greenHealth.getWidth()+1);
        UIdelay = 0;
    }
    this->inv.render(g);
    greenHealth.render(g, sf::Color::Green);
};

void Player::update()
{
    double speed = this->speed + (this->speed * stats.get("Speed"))/100;

    if(keys[0]) velocity.y = -speed;
    else if(keys[2]) velocity.y = speed;
    else velocity.y = 0;

    if(keys[1]) velocity.x = -speed;
    else if(keys[3]) velocity.x = speed;
    else velocity.x = 0;

    handleCollisions();

    UIdelay += DeltaTime::get();
};

void Player::handleCollisions()
{
    for(Token* t: collisions)
    {

        if(Skill* s = dynamic_cast<Skill*>(t))
        {

            if(s->canPickUp())
            {
                s->pickUp();
                inv.add(s, 1);
            }
        }
        
        if(Firewall* fw = dynamic_cast<Firewall*>(t))
        {
            dealDamage(fw->dealDamage(this));
            continue;
        }

        if(Bazooka* b = dynamic_cast<Bazooka*>(t))
        {
            if(!b->isImmuneToPlayer())
            {
                dealDamage(b->damage());
            }
            continue;
        }
        
    }

}

void Player::handleEvents(sf::Event e, sf::RenderWindow* g)
{

    if(e.type == sf::Event::KeyPressed)
    {
        if(e.key.code == sf::Keyboard::W)
        {
            keys[0] = true;
        }
        if(e.key.code == sf::Keyboard::A)
        {
            keys[1] = true;
        }
        if(e.key.code == sf::Keyboard::S)
        {
            keys[2] = true;
        }
        if(e.key.code == sf::Keyboard::D)
        {
            keys[3] = true;
        }
        if(e.key.code == sf::Keyboard::Num1)
        {
            inv.select(0);
        }
        if(e.key.code == sf::Keyboard::Num2)
        {
            inv.select(1);
        }
        if(e.key.code == sf::Keyboard::Num3)
        {
            inv.select(2);
        }
        if(e.key.code == sf::Keyboard::Num4)
        {
            inv.select(3);
        }
        if(e.key.code == sf::Keyboard::Num5)
        {
            inv.select(4);
        }
        if(e.key.code == sf::Keyboard::Num6)
        {
            inv.select(5);
        }
        if(e.key.code == sf::Keyboard::Num7)
        {
            inv.select(6);
        }
        if(e.key.code == sf::Keyboard::Num8)
        {
            inv.select(7);
        }
        if(e.key.code == sf::Keyboard::Num9)
        {
            inv.select(8);
        }
    }
    
    if(e.type == sf::Event::KeyReleased)
    {
        if(e.key.code == sf::Keyboard::W)
        {
            keys[0] = false;
        }
        if(e.key.code == sf::Keyboard::A)
        {
            keys[1] = false;
        }
        if(e.key.code == sf::Keyboard::S)
        {
            keys[2] = false;
        }
        if(e.key.code == sf::Keyboard::D)
        {
            keys[3] = false;
        }
    }
    
    if(e.type == sf::Event::Resized)
    {
        windowSize = sf::Vector2f(e.size.width, e.size.height);
    }
    
    mousePos = Hitbox(sf::Mouse::getPosition(*g).x*(g->getDefaultView().getSize().x/windowSize.x), sf::Mouse::getPosition(*g).y*(g->getDefaultView().getSize().y/windowSize.y), 1, 1);
};

Hitbox Player::mousePosition()
{
    return mousePos;
};

Skill* Player::getSelected()
{
    return inv.getSelected();
};

void Player::useSkill()
{
    inv.remove(inv.getSelected());
};

Inventory& Player::getInv()
{
    return inv;
};

std::string Player::getName()
{
    return name;
};

std::string Player::save()
{
    std::string items;

    return name + " " + std::to_string(health) + " " + std::to_string(maxWave) + " ," + inv.save() + " " + std::to_string(money) + " " + stats.save();
}

void Player::setMaxWave(int i)
{
    if(maxWave < i)
        maxWave = i;
}

double Player::getStat(std::string name)
{
    return stats.get(name);
}

void Player::dealDamage(int damage)
{
    //std::cout<<"Before: "<<health<<std::endl;
    health -= (damage - (damage * stats.get("Protection"))/150);
    //std::cout<<"After: "<<health<<std::endl;
}

PlayerStats& Player::getStats()
{
    return stats;
}

void Player::increaseStat(std::string name, int i)
{
    stats.add(name, i);
}