#include "Player.hpp"

Player::Player(double x, double y, double width, double height, std::string name) : Character(x,y,width,height), mousePos(0,0,1,1),
redHealth(10,10,100,40),
greenHealth(10,10,100,40)
{
    keys = {false, false, false, false};
    speed = 5;
    windowSize = sf::Vector2f(800,800);
    for(int i = 0 ; i< 10; i ++)
    {
        inv.add(new Bazooka(0, 0, 1, true));
        inv.add(new Firewall(0, 0, 1));
    }
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
};

Player::~Player()
{
};

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
        UIdelay = 0;
    }
    this->inv.render(g);
    greenHealth.render(g, sf::Color::Green);
};

void Player::update()
{
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