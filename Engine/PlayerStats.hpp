#pragma once

#include<string>
#include<vector>
#include<unordered_map>

class PlayerStats
{
private:
    std::unordered_map<std::string, double> stats;
public:
    PlayerStats(std::vector<std::string> = {});
    ~PlayerStats();
    std::string save();
    double get(std::string);
    void add(std::string, int i = 1);
    int size();
    std::unordered_map<std::string, double>  copy();
};