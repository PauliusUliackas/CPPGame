#include "Database.hpp"

typedef std::pair<Skill*, double> p;
std::vector<std::pair<Skill*, double>> Database::db = {p{new Firewall(0, 0, 1), 0}, p{new Bazooka(0, 0, 1, true), 40}};

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