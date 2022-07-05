#pragma once

#include "../Entities/Swat.hpp"
#include "../Map/Map.hpp"

#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

class Spawner
{
private:
    int wave;
    double descisionTime;
    std::vector<Enemy*> database;

public:
    Spawner();
    ~Spawner();
    std::vector<Enemy*> spawn(Map* map, bool);
    
};
