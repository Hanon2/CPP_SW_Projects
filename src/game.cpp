#include "game.h"

#include <iostream>

using namespace std;

void runGame(Land* map[MAP_SIZE][MAP_SIZE], Player &p)
{ 
    cout << "You wake up and find yourself lost in the middle of a strange wilderness.\n";
    
    while(p.isAlive())
    {
        //These 2 if else statements handle the rolling back of the player if the player exceeded the max x or y position.
        if (p.x > MAP_SIZE-1) 
        {
            p.x=0;
        } 
        else if (p.x < 0) 
        {
            p.x = 9;
        }
        if (p.y > 9) 
        {
            p.y=0;
        } 
        else if (p.y<0) 
        {
            p.y = 9;
        }
        cout << "To the north you see " << map[p.x][p.y - 1]->getDescription() << endl;
        cout << "To the east you see " << map[p.x + 1][p.y]->getDescription() << endl;
        cout << "To the south you see " << map[p.x][p.y + 1]->getDescription() << endl;
        cout << "To the west you see " << map[p.x - 1][p.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:\n";
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'N': case 'n': p.y = p.y - 1;break;
            case 'E': case 'e': p.x = p.x + 1;break;
            case 'S': case 's': p.y = p.y + 1;break;
            case 'W': case 'w': p.x  = p.x - 1; break;
            default: cout<<"Wrong input, please enter N,W,E,S\n";userInput = 'x';break;
        }
        
        if (userInput!='x')
        {
            cout << map[p.x][p.y]->visit(p) << endl;
            p.takeTurn();
            cout << p.getStats() << endl;
        }
    }
    
    cout << "You died.\nYour score is: "<< p.getScore()<< endl;
}