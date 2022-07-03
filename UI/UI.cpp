#include "UI.hpp"

UI::UI()
{
};

UI::~UI()
{
};

void UI::render(sf::RenderWindow* g, Player p)
{
    p.handleUI(g);
};