#include <iostream>
#include <cstdlib>
#include <ctime>


#include "player.h"
#include "map.h"
#include "lands.h"
#include "game.h"
#include "doubly.h"


void runDll()
{
    doublylinkedlist dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    doublylinkedlist dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    dll.print();
    dllCopy.print();
    
    dll = dllCopy;
    dll.print();
}
int main()
{
    char input; 
    while (input != 'x')
    {
        cout << "This program combines different projects. Choose which program you would like to run or enter x to exit:\n"
         << "1 - Survival Game: A wilderness survival simulation.\n"
         << "2 - Double Linked List: A data structure project that demonstrates the operations of a doubly linked list.\n"
         << "3 - File Encryption: A file encryption tool that secures files by applying encryption.\n";

        cin>>input; 
        if ('1' == input)
        {
            srand(time(0));
            Land* map[MAP_SIZE][MAP_SIZE];

            populateMap(map);

            Player player(MAP_SIZE / 2, MAP_SIZE / 2); // Start in the middle
            runGame(map, player); // Pass player by reference
            cleanMap(map);   
        }
        else if ('2' == input)runDll(); 
    }

    return 0;
}