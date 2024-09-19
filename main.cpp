#include <iostream>
#include <cstdlib>
#include <ctime>


#include "player.h"
#include "map.h"
#include "lands.h"


int main()
{
    srand(time(0));
    Land* map[MAP_SIZE][MAP_SIZE];
    populateMap(map);
    
    Player player(MAP_SIZE/2, MAP_SIZE/2); //Start in the middle
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness.\n";
    

    while(player.isAlive())
    {
        //These 2 if else statements handle the rolling back of the player if the player exceeded the max x or y position.
        if (player.x > MAP_SIZE-1) 
        {
            player.x=0;
        } 
        else if (player.x < 0) 
        {
            player.x = 9;
        }
        if (player.y > 9) 
        {
            player.y=0;
        } 
        else if (player.y<0) 
        {
            player.y = 9;
        }
        cout << "To the north you see " << map[player.x][player.y - 1]->getDescription() << endl;
        cout << "To the east you see " << map[player.x + 1][player.y]->getDescription() << endl;
        cout << "To the south you see " << map[player.x][player.y + 1]->getDescription() << endl;
        cout << "To the west you see " << map[player.x - 1][player.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:\n";
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'N': case 'n': player.y = player.y - 1;break;
            case 'E': case 'e': player.x = player.x + 1;break;
            case 'S': case 's': player.y = player.y + 1;break;
            case 'W': case 'w':player.x  = player.x - 1; break;
            default: cout<<"Wrong input, please enter N,W,E,S\n";userInput = 'x';break;
        }
        
    if (userInput!='x')
    {
        cout << map[player.x][player.y]->visit(player) << endl;
        
        player.takeTurn();
        cout << player.getStats() << endl;
    }
    }
    
    cout << "You died.\nYour score is: "<< player.getScore()<< endl;
    cleanMap(map);
    return 0;
}