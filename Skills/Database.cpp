#include "Database.hpp"

typedef std::pair<Skill*, double> p;
std::vector<std::pair<Skill*, double>> Database::db = {p{new Firewall(0, 0, 1), 0}, p{new Bazooka(0, 0, 1, true), 40}, p{new Healthpot(0,0,1), 200}, p{new Shield(0,0,1), 15}, p{new GoldBag(0,0,1), 5}};

Database::Database(/* args */)
{
    
};

Database::~Database()
{
};

void Database::loadCooldowns(std::unordered_map<std::string, std::pair<double,double>>& list)
{
    for(std::pair<Skill*, double> pair: db)
    {
        list[pair.first->namae()] = {0, pair.second};
    }
}

Skill* Database::getByName(std::string name)
{
    for(std::pair<Skill*, double> pair: db)
    {
        if(pair.first->namae() == name) return pair.first->copy();
    }
    std::cout<<"No such Skill: "<<name<<std::endl;
    throw("SIUUU");
};

Skill* Database::getRandom()
{
    return db[std::rand()%(db.size())].first;
}

Skill* Database::randomRarity()
{
    int percentage = std::rand()%100+1;
    int rarity;

    if(percentage <= 40)
    {
        rarity = 0;
    }
    else if(percentage <= 70)
    {
        rarity = 1;
    } 
    else if(percentage <= 85)
    {
        rarity = 2;
    }
    else if(percentage <= 93)
    {
        rarity = 3;
    }
    else if(percentage <= 99)
    {
        rarity = 4;
    }
    else rarity = 5;

    std::vector<Skill*> pool;

    while(pool.size() == 0)
    {
        pool = getRarity(rarity);
        rarity--;
    }

    return pool[std::rand()%(pool.size())];
};

std::vector<Skill*> Database::getRarity(int i)
{
    std::vector<Skill*> out;

    for(auto x: db)
    {
        if(x.first->getRarity() == i) out.push_back(x.first);
    }
    return out;
}