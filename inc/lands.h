

/*
==========================================
        Survival Game
==========================================


Module name: lands.h
Author: Mohamed Abdelmoneim
Date: 09/18/2024



Key Features:
--------------

    - Each land offers unique challenges or benefits when visited:
    - **Forest**: Chance of finding food or being attacked by a bear.
    - **Lake**: Restores thirst by drinking clean water.
    - **Hospital**: Fully restores health.
    - **Iced Land**: Decreases health due to cold conditions.
    - **Farm**: Increases hunger by providing food.
    - **Camp**: Increases both hunger and thirst.
    - **Basketball Field**: Decreases thirst due to physical activity.
    - **Haunted House**: Presents a riddle, math problem, or general knowledge question. 
    Correct answers maintain health, while incorrect ones decrease it.
    - **Lives Shop**: Restores health by 1.
    - **Grocery Store**: Fully restores hunger.
*/

#ifndef LANDS_H
#define LANDS_H

#include <iostream>
#include <sstream>
#include <string>


#include "player.h"

using namespace std;



class Land 
{
    public:
        virtual string getDescription() = 0;
        virtual string visit(Player& p) = 0;
};

class Forest : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class Lake : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class Hospital : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);

};

class IcedLand : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class Farm : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class Camp : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class BasketBallField : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class HauntedHouse : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
    private:
        int randomVarToPickTheQuestion; // Variable to control the challenge in the haunted house
};

class LivesShop : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

class GroceryStore : public Land 
{
    public:
        string getDescription();
        string visit(Player& p);
};

#endif
