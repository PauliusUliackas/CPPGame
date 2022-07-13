#include "PlayerStats.hpp"
//#include <iostream>

PlayerStats::PlayerStats(std::vector<std::string> list)
{
    stats["Cooldown"] = 0;
    stats["Protection"] = 0;
    stats["Speed"] = 0;

    for(int i = 0; i < list.size(); i+=2)
    {
        //std::cout<<list[i]<<" "<<list[i+1]<<std::endl;
        stats[list[i]] = std::stod(list[i+1]);
    }
}

PlayerStats::~PlayerStats()
{
}

std::string PlayerStats::save()
{
    std::string out = "";
    for(auto pair: stats)
    {
        //std::cout<<pair.first<<" "<<pair.second<<std::endl;
        out += "*" + pair.first + "*" + std::to_string(pair.second);
    }
    return out;
};

double PlayerStats::get(std::string name)
{
    return stats[name];
}

void PlayerStats::add(std::string name, int i)
{
    stats[name]+=i;
    if(stats[name] > 100) stats[name] = 100;
}

int PlayerStats::size()
{
    return stats.size();
}

std::unordered_map<std::string, double>  PlayerStats::copy()
{
    return stats;
}