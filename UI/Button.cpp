#include "Button.hpp"


Button::Button(double x, double y, std::string name, int scl): hb(x, y, 0, 0)
{
    txt.loadFromFile("Art/"+name+".png");
    sprite.setTexture(txt);
    sprite.setPosition(x, y);
    sprite.scale(scl,scl);
    hb.setWidth(sprite.getGlobalBounds().width);
    hb.setHeight(sprite.getGlobalBounds().height);
    font.loadFromFile("Art/BadComic-Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(16);
    text.setColor(sf::Color::Yellow);
}

Button::~Button()
{
}

bool Button::render(sf::RenderWindow* g, Hitbox mouse, bool isPressed)
{
    g->draw(sprite);
    if(mouse.intersects(hb))
    {
        text.setPosition(mouse.getX(), mouse.getY()-16);
        g->draw(text);
    }
    return mouse.intersects(hb) && isPressed;
};

void Button::setLabel(std::string label)
{
    text.setString(label);
}