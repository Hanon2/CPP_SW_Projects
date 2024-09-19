

/*
==========================================
        Survival Game
==========================================


Module name: player.h
Author: Mohamed Abdelmoneim
Date: 09/18/2024



Key Features:
--------------
    - The player starts at the center of a 10x10 map with maximum health, hunger, and thirst.
    - Health decreases if hunger or thirst drops to zero. The game ends when the player's health reaches zero.
    - The player's score increases with each move, representing their progress in the game.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


#define MAX_HEALTH  (3)
#define MAX_HUNGER  (5)
#define MAX_THIRST  (3)


class Player 
{
    public:
        Player(int x, int y);
        int getScore() const;
        void takeDamage(int val);
        void takeTurn();
        string getStats() const;
        bool isAlive() const;
        void modifyThirst(int val);
        void increaseHunger(int val);
        void increaseHealth(int val);
        int x, y;

    private:
        int health, hunger, thirst, score;
};

#endif
