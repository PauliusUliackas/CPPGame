#include "Bazooka.hpp"

Bazooka::Bazooka(double x, double y, int state, bool immune) : Skill("Bazooka",x,y,state)
{
    texture.loadFromFile("Art/BazookaIcon.png");
    icon.setTexture(texture);
    icon.scale(4,4);
    speed = 7;
    hitbox.setX(x);
    collided = false;
    immuneToPlayer = immune;
    distance = 0;
}

Bazooka::~Bazooka()
{
    
}

void Bazooka::render(sf::RenderWindow* g)
{
    Skill::render(g);
    if(state == ACTIVE)
    {
        icon.setPosition(hitbox.getX() + ( hitbox.getWidth()) / 2, hitbox.getY() + (hitbox.getHeight()) / 2);
        g->draw(icon);
    }
    //hitbox.render(g, sf::Color::Black);
};

void Bazooka::update()
{
    if(state == ACTIVE)
    {
        double xVel = velocity.x * DeltaTime::get();
        double yVel = velocity.y * DeltaTime::get();

        distance = magnitude(sub(from, sf::Vector2f(hitbox.getX(), hitbox.getX())));

        hitbox.moveBy(xVel, yVel);
    }
}

void Bazooka::activate(Tile& location, sf::Vector2f from)
{
    Skill::activate(location, from);
    shoot(from, sf::Vector2f(location.getHitbox().getX(), location.getHitbox().getY()));
};

void Bazooka::shoot(sf::Vector2f from, sf::Vector2f to)
{
    sf::Vector2f trajectory = sub(from, to);
    velocity = -mult(normalise(trajectory), speed);
    this->from = from;
    double angle = std::atan2(trajectory.y, trajectory.x)*180/3.14-90;
    icon.setOrigin((icon.getLocalBounds().left + icon.getLocalBounds().width) / 2, (icon.getLocalBounds().top + icon.getLocalBounds().height) / 2);
    hitbox.setOrigin((hitbox.getX() + hitbox.getWidth()) / 2, (hitbox.getY() + hitbox.getHeight()) / 2);
    hitbox.setX(from.x);
    hitbox.setY(from.y);
    icon.setRotation(angle);
    hitbox.rotate(angle);
}

bool Bazooka::canActivate(Tile& tile, Character* c)
{
    return Skill::canActivate(tile, c);
}

Bazooka* Bazooka::copy()
{
    return new Bazooka(0, 0, state, immuneToPlayer);
};

bool Bazooka::isOver()
{
    return collided || (Skill::isOver() && collisions.size()) || distance > 900;
};

int Bazooka::damage()
{
    if(state == ACTIVE){
        collided = true;
        
        return 10;
    } 
    return 0;
};

bool Bazooka::isImmuneToPlayer()
{
    return immuneToPlayer;
};


