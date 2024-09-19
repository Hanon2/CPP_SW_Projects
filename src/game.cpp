#include "game.h"
#include <iostream>

using namespace std;

// Modified runGame function for multiple players
void runGame(Land* map[MAP_SIZE][MAP_SIZE], Player* players, int numPlayers)
{ 
    cout << "You wake up and find yourself lost in the middle of a strange wilderness.\n";
    
    bool gameRunning = true;
    while (gameRunning)
    {
        for (int i = 0; i < numPlayers; ++i)
        {
            if (!players[i].isAlive())
                continue; // Skip dead players

            Player &p = players[i];
            cout << "Player " << i + 1 << "'s turn:\n";

            // Handle the player's move
            if (p.x > MAP_SIZE - 1) 
            {
                p.x = 0;
            } 
            else if (p.x < 0) 
            {
                p.x = MAP_SIZE - 1;
            }
            if (p.y > MAP_SIZE - 1) 
            {
                p.y = 0;
            } 
            else if (p.y < 0) 
            {
                p.y = MAP_SIZE - 1;
            }

            // Display surroundings
            cout << "To the north you see " << map[p.x][p.y - 1]->getDescription() << endl;
            cout << "To the east you see " << map[p.x + 1][p.y]->getDescription() << endl;
            cout << "To the south you see " << map[p.x][p.y + 1]->getDescription() << endl;
            cout << "To the west you see " << map[p.x - 1][p.y]->getDescription() << endl;

            cout << "Which way will you go? Enter N, E, S, or W:\n";
            char userInput;
            cin >> userInput;
            
            switch(userInput){
                case 'N': case 'n': p.y = p.y - 1; break;
                case 'E': case 'e': p.x = p.x + 1; break;
                case 'S': case 's': p.y = p.y + 1; break;
                case 'W': case 'w': p.x = p.x - 1; break;
                default: cout << "Wrong input, please enter N,W,E,S\n"; userInput = 'x'; break;
            }

            if (userInput != 'x')
            {
                cout << map[p.x][p.y]->visit(p) << endl;
                p.takeTurn();
                cout << p.getStats() << endl;
            }

            if (!p.isAlive())
            {
                cout << "Player " << i + 1 << " has died.\n";
                cout << "Player " << i + 1 << " score: " << p.getScore()<<endl;
            }
        }

        // Check if the game is still running (at least one player alive)
        gameRunning = false;
        for (int i = 0; i < numPlayers; ++i)
        {
            if (players[i].isAlive())
            {
                gameRunning = true;
                break;
            }
        }
    }

    cout << "Game over.\n";
}
