#include "Button.hpp"


Button::Button(double x, double y, std::string name, int scl): hb(x, y, 0, 0)
{
    txt.loadFromFile("Art/"+name+".png");
    sprite.setTexture(txt);
    sprite.setPosition(x, y);
    sprite.scale(scl,scl);
    hb.setWidth(sprite.getGlobalBounds().width);
    hb.setHeight(sprite.getGlobalBounds().height);
}

Button::~Button()
{
}

bool Button::render(sf::RenderWindow* g, Hitbox mouse, bool isPressed)
{
    g->draw(sprite);
    return mouse.intersects(hb) && isPressed;
};