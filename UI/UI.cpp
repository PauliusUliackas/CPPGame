#include "UI.hpp"

UI::UI()
{
    font.loadFromFile("Art/BadComic-Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(16);
    text.setPosition(700,20);
};

UI::~UI()
{
};

void UI::render(sf::RenderWindow* g, Player p)
{
    p.handleUI(g);
    text.setString("Money: " + std::to_string(p.money));
    g->draw(text);
};