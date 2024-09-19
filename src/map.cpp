#include <cstdlib>

#include <cstdlib>
#include <ctime>
#include "map.h"

void populateMap(Land* map[MAP_SIZE][MAP_SIZE])
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            int randomNum = rand() % 9;
            switch (randomNum)
            {
                case 0: map[i][j] = new Forest; break;
                case 1: map[i][j] = new Lake; break;
                case 2: map[i][j] = new HauntedHouse; break;
                case 3: map[i][j] = new LivesShop; break;
                case 4: map[i][j] = new GroceryStore; break;
                case 5: map[i][j] = new IcedLand; break;
                case 6: map[i][j] = new Hospital; break;
                case 7: map[i][j] = new Farm; break;
                case 8: map[i][j] = new Camp; break;
                default: break;
            }
        }
    }
}

void cleanMap(Land* map[MAP_SIZE][MAP_SIZE])
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            delete map[i][j];
            map[i][j] = nullptr;
        }
    }
}