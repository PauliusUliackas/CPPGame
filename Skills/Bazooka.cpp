#include "Bazooka.hpp"

Bazooka::Bazooka(double x, double y, int state) : Skill("Bazooka",x,y,state)
{
    texture.loadFromFile("Art/BazookaIcon.png");
    icon.setTexture(texture);
    icon.scale(4,4);
    speed = 1;
}

Bazooka::~Bazooka()
{
}

void Bazooka::render(sf::RenderWindow* g)
{

    Skill::render(g);

    if(state == ACTIVE)
    {
        icon.setPosition(hitbox.getX(), hitbox.getY());
        g->draw(icon);
    }
};

void Bazooka::update()
{
    hitbox.setX(from.x);
    hitbox.setY(from.y);
    from.x += velocity.x;
    from.y += velocity.y;
}

void Bazooka::activate(Tile& location)
{
    Skill::activate(location);
    shoot(from, sf::Vector2f(location.getHitbox().getX(), location.getHitbox().getY()));
};

void Bazooka::shoot(sf::Vector2f from, sf::Vector2f to)
{
    sf::Vector2f trajectory = sub(from, to);
    velocity = -mult(normalise(trajectory), speed);
    this->from = from;
}

bool Bazooka::canActivate(Tile& tile, Character* c)
{
    from = sf::Vector2f(c->getHB().getX(), c->getHB().getY());
    return Skill::canActivate(tile, c);
};

Bazooka* Bazooka::copy()
{
    return new Bazooka(hitbox.getX(), hitbox.getY(), state);
};

bool Bazooka::isOver()
{
    return false;
};


