#include "Spawner.hpp"

Spawner::Spawner()
{
    wave = 0;
    descisionTime =  0;
    Swat* swat =new Swat(0,0);
    database.push_back(swat);
};

Spawner::~Spawner()
{
};

std::vector<Enemy*> Spawner::spawn(Map* map, bool tick)
{

    if(!tick)
        descisionTime += DeltaTime::get();

    std::vector<Enemy*> out;
    if(descisionTime > 200)
    {
        wave++;
        descisionTime = 0;

        for(int i = 0; i < wave; i++)
        {
            Tile* t = map->getRandomSpawn();
            int index = std::rand() % database.size();
            out.push_back(database.at(index)->spawn(t->getHitbox().getX(), t->getHitbox().getY()));
        }
    }
    return out;
}