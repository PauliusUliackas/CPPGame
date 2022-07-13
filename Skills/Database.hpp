#pragma once

#include "Firewall.hpp"
#include "Bazooka.hpp"
#include "Healthpot.hpp"
#include "Shield.hpp"
#include "GoldBag.hpp"
#include<ctime>

class Database
{
private:
    static std::vector<std::pair<Skill*, double>> db;
public:
    Database();
    ~Database();
    static void loadCooldowns(std::unordered_map<std::string, std::pair<double,double>>&);
    static Skill* getByName(std::string);
    static Skill* getRandom();
    static Skill* randomRarity();
    static std::vector<Skill*> getRarity(int);
};
