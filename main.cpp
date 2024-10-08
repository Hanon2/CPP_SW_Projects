#include <iostream>
#include <cstdlib>
#include <ctime>

#include "player.h"
#include "map.h"
#include "lands.h"
#include "game.h"
#include "doubly.h"


int main()
{
    char input; 
    while (input != 'x')
    {
        cout << "This program combines different projects. Choose which program you would like to run or enter x to exit:\n"
         << "1 - Survival Game: A wilderness survival simulation.\n"
         << "2 - Double Linked List: A data structure project that demonstrates the operations of a doubly linked list.\n";
        cin>>input; 
        if ('1' == input)
        {
            char numOfPlayersInput;
            int numberOfPlayers;
            while (true)
            {
                
                cout<<"Enter the number of players that are playing or x to exit>>>\n";
                cin>>numOfPlayersInput;
                if (isdigit(numOfPlayersInput))
                {
                    numberOfPlayers = numOfPlayersInput - '0';
                    if (numberOfPlayers<=0) cout<<"The number of players need to be a positive integer>>>\n";
                    else break;
                }
                else if ((numOfPlayersInput == 'x') || (numOfPlayersInput =='X')) exit(0);
                else cout<<"Wrong input\n";
            }
            Player players[numberOfPlayers];
            for (int i =0; i<numberOfPlayers; ++i) players[i] = Player(MAP_SIZE / 2, MAP_SIZE / 2); // Start in the middle);
            srand(time(0));
            Land* map[MAP_SIZE][MAP_SIZE];
            populateMap(map);
            runGame(map, players, numberOfPlayers); // Pass player by reference
            cleanMap(map);   
        }
        else if ('2' == input)
        {
            doublylinkedlist dll;
            string dllInput;
            while (true)
            {
                cout<<"Enter the operation you would like to do to the DLL, h for help, or any other key to exit\n";
                cin>> dllInput;
                if (dllInput == "h" or dllInput == "H")
                {
                    for (int i =1; i<DLL_NUM_OF_CMD; ++i) cout<<dll.getCommandString((dll_cmd_t)i)<<endl;
                }
                else if (dllInput == "x" or dllInput == "X") exit(0);
                else if (stoi(dllInput) > (DLL_NUM_OF_CMD-1)) cout << "Wrong command \n";
                else dll.handleInput(dllInput);
            }
        }
    }

    return 0;
}