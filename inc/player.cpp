#include <iostream>
#include <sstream>
#include <string>
#include "player.h"


Player::Player(int x, int y)
{
    health = MAX_HEALTH;
    hunger = MAX_HUNGER;
    thirst = MAX_THIRST;
    this->x = x;
    this->y = y;
    score = 0;
}

int Player::getScore() const 
{
    return score;
}

void Player::takeDamage(int val)
{
    health -= val;
    if (health < 0) health = 0;
}

void Player::takeTurn()
{
    thirst--;
    hunger--;
    if (thirst <= 0)
    {
        health--;
        thirst = 0;
    }
    if (hunger <= 0)
    {
        health--;
        hunger = 0;
    }
    score++;
}

string Player::getStats() const 
{
    stringstream ss;
    ss << "============\n"
       << "Health: " << health << endl 
       << "Hunger: " << hunger << endl 
       << "Thirst: " << thirst << endl
       << "============\n";
    return ss.str();
}

bool Player::isAlive() const 
{
    return health > 0;
}

void Player::modifyThirst(int val)
{
    thirst += val;
    if (thirst > MAX_THIRST) thirst = MAX_THIRST;
    else if (thirst < 0) thirst = 0;
}

void Player::increaseHunger(int val)
{
    hunger += val;
    if (hunger > MAX_HUNGER) hunger = MAX_HUNGER;
}

void Player::increaseHealth(int val)
{
    health += val;
    if (health > MAX_HEALTH) health = MAX_HEALTH;
}