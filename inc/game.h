/*
==========================================
        Survival Game
==========================================


Module name: game.h
Author: Mohamed Abdelmoneim
Date: 09/18/2024



Key Features:
--------------
    - The **runGame** function controls the main game loop.
    - Handles player movement and checks for map boundaries to wrap around the edges.
    - Displays descriptions of adjacent map tiles based on the player's current position.
    - Processes user input to move the player in different directions (North, East, South, West).
    - Updates the player's state and prints statistics after each move.
    - Ends the game when the player’s health reaches zero and displays the final score.
*/
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "lands.h"
#include "map.h"

void runGame(Land* map[MAP_SIZE][MAP_SIZE], Player* players, int numPlayers);

#endif
