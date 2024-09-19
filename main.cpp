#include <iostream>
#include <cstdlib>
#include <ctime>


#include "player.h"
#include "map.h"
#include "lands.h"
#include "game.h"

int main()
{
    srand(time(0));
    Land* map[MAP_SIZE][MAP_SIZE];
    
    populateMap(map);
    
    Player player(MAP_SIZE / 2, MAP_SIZE / 2); // Start in the middle
    runGame(map, player); // Pass player by reference
    cleanMap(map);
    return 0;
}