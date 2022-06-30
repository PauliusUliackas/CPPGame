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
                Token* token = tokens[i];
                tokens.erase(tokens.begin()+i);
                delete token;
            }
        }
    }
    rubbish.clear();

    for(Token* t: tokens)
    {
        t->update();
        if(Character* c = dynamic_cast<Character*>(t))
        {
            move(c);
        }
        if(Skill* skill = dynamic_cast<Skill*>(t))
        {
            if(skill->isOver()) this->removeToken(skill);
        }
    }

};

void TokenHandler::move(Character* c)
{

    std::vector<Token*> allCollisions;
    std::vector<Token*> collisions;

    sf::Vector2f velocity = c->speed();

    c->moveBy(velocity.x * DeltaTime::get(), 0);

    collisions = getCollisions(c);

    for(Token* t: collisions)
    {
        if(t->isSolid()){
            if(velocity.x > 0)
            {
                c->leftOf(t);
            }
            if(velocity.x < 0)
            {
                c->rightOf(t);
            }
        }
        allCollisions.push_back(t);
    }

    collisions.clear();

    c->moveBy(0, velocity.y * DeltaTime::get());

    collisions = getCollisions(c);

    for(Token* t: collisions)
    {
        if(t->isSolid()){
            if(velocity.y > 0)
            {
                c->topOf(t);
            }
            if(velocity.y < 0)
            {
                c->bottomOf(t);
            }
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