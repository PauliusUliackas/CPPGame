#include "Token.hpp"

Token::Token(double x, double y, double width, double height) :
hitbox(x, y, width, height),
anime(7)
{
    solid = true;
};

Token::~Token()
{
    
};

void Token::render(sf::RenderWindow* g)
{
    hitbox.render(g);
};

void Token::update()
{
    
};

void Token::moveBy(double x, double y)
{
    hitbox.moveBy(x,y);
};

bool Token::operator==(const Token* t)
{
    return t == this;
};

bool Token::operator<(const Token* t)
{
    return hitbox.getY() < t->hitbox.getY();
};

bool Token::isSolid()
{
    return solid;
};

bool Token::collides(Token* other)
{
    return hitbox.intersects(other->hitbox);
};

void Token::setX(double x)
{
    hitbox.setX(x);
};

void Token::setY(double y)
{
    hitbox.setY(y);
};

void Token::leftOf(Token* t)
{
    hitbox.setX(t->hitbox.getX() - hitbox.getWidth());
};

void Token::rightOf(Token* t)
{
    hitbox.setX(t->hitbox.getX() + t->hitbox.getWidth());
};

void Token::topOf(Token* t)
{
    hitbox.setY(t->hitbox.getY() - hitbox.getHeight());
};

void Token::bottomOf(Token* t)
{
    hitbox.setY(t->hitbox.getY() + t->hitbox.getHeight());
};

Hitbox Token::getHB()
{
    return hitbox;
};