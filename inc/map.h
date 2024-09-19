#include "lands.h"

/*
==========================================
        Survival Game
==========================================


Module name: map.h
Author: Mohamed Abdelmoneim
Date: 09/18/2024



Key Features:
--------------
    - The game map is randomly populated with different types of lands that affect the player's stats (health, hunger, and thirst).
    - The player can move north, east, south, or west. 
    - The map wraps around, meaning if the player moves off one side, they appear on the opposite side.
*/

#ifndef MAP_H
#define MAP_H

#include "lands.h"


#define MAP_SIZE   (10)

void populateMap(Land* map[MAP_SIZE][MAP_SIZE]);
void cleanMap(Land* map[MAP_SIZE][MAP_SIZE]);

#endif