#pragma once

#include "Firewall.hpp"
#include "Bazooka.hpp"

class Database
{
private:
    static std::vector<std::pair<Skill*, double>> db;
public:
    Database();
    ~Database();
    static void loadCooldowns(std::unordered_map<std::string, std::pair<double,double>>&);
    static Skill* getByName(std::string);
};
