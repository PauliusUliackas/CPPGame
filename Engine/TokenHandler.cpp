#include "TokenHandler.hpp"

std::vector<Token*> TokenHandler::add = {};
std::vector<Token*> TokenHandler::rubbish = {};
std::vector<Token*> TokenHandler::tokens = {};

TokenHandler::TokenHandler()
{
    
};

TokenHandler::~TokenHandler()
{
};

void TokenHandler::addToken(Token* t)
{
    add.push_back(t);
};

void TokenHandler::removeToken(Token* t)
{
    rubbish.push_back(t);
};

void TokenHandler::render(sf::RenderWindow* g)
{
    for(Token* t: tokens)
    {
        t->render(g);
    }
};

void TokenHandler::update()
{
    for(Token* t: add)
    {
        tokens.push_back(t);
    }
    add.clear();
    
    for(Token* t: rubbish)
    {
        for(int i = 0; i < tokens.size(); i++)
        {
            if(t == tokens.at(i))
            {
                tokens.erase(tokens.begin()+i);
            }
        }
    }
    rubbish.clear();

    for(Token* t: tokens)
    {
        t->update();
    }
};

void TokenHandler::move(Character* c, sf::Vector2f velocity)
{

    std::vector<Token*> allCollisions;
    std::vector<Token*> collisions;

    c->moveBy(velocity.x * DeltaTime::get(), 0);

    collisions = getCollisions(c);

    for(Token* t: collisions)
    {
        if(velocity.x > 0) // moving right
        {
            c->leftOf(t);
        }
        if(velocity.x < 0)
        {
            c->rightOf(t);
        }
        allCollisions.push_back(t);
    }

    collisions.clear();

    c->moveBy(0, velocity.y * DeltaTime::get());

    collisions = getCollisions(c);

    for(Token* t: collisions)
    {
        if(velocity.y > 0)
        {
            c->topOf(t);
        }
        if(velocity.y < 0)
        {
            c->bottomOf(t);
        }
        allCollisions.push_back(t);
    }

    c->setCollisions(allCollisions);

};

std::vector<Token*> TokenHandler::getCollisions(Character* c)
{
    std::vector<Token*> collisions;
    for(Token* t: tokens)
    {
        if(t->collides(c) && c != t) collisions.push_back(t);
    }
    return collisions;
};