#pragma once

#include "Item.hpp"
#include "Drop.hpp"

class Database
{
private:
    std::vector<Item*> items;
    std::vector<Drop*> drops;

public:
    Database();
    ~Database();
    Drop* drop(int id);
    Item* item(int id);
    
};
