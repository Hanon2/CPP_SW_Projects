#include <iostream>
#include <sstream>
/*
==========================================
        Survival Game
==========================================

Author: Mohamed Abdelmoneim
Date: 09/18/2024


Synopsys: 
- This is a text-based survival game where the player navigates through different types of lands on a randomly generated map. 
- The objective of the game is to survive as long as possible while managing health, hunger, and thirst.




Key Features:
--------------
1. **Player**:
   - The player starts at the center of a 10x10 map with maximum health, hunger, and thirst.
   - Health decreases if hunger or thirst drops to zero. The game ends when the player's health reaches zero.
   - The player's score increases with each move, representing their progress in the game.

2. **Map**:
   - The game map is randomly populated with different types of lands that affect the player's stats (health, hunger, and thirst).
   - The player can move north, east, south, or west. 
   The map wraps around, meaning if the player moves off one side, they appear on the opposite side.

3. **Lands**:
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


#include <time.h>

using namespace std;

#define MAX_HEALTH  (3)
#define MAX_HUNGER  (5)
#define MAX_THIRST  (3)
#define MAP_SIZE   (10)

/* This is a class that declares a player in the game.
* Each method would affect the player parameters such as score, health etc..
* This class has 6 different variables:
1- x&y: Represents the current x&y axis position of the player on the map. 
2- health: Represents the current health of the player. If health is zero, then the player died.
3- hunger & thirst: Represents the level of hunger and thirst
   this player is at. If the hunger is zero then the health will be decremented by 1.
4- score: Represents the score of the player. Each time the player moves to another land on the map score will be incremented by 1.
*/
class Player 
{
    public:
    Player(int x, int y)
    {
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        
        this->x = x;
        this->y = y;
        score = 0;
    }
    
    int getScore() const 
    {
        return score;
    }
    
    void takeDamage(int val)
    {
        health -= val;
        if(health < 0) health = 0;
    }
    
    void takeTurn()
    {
        thirst--;
        hunger--;
        
        if(thirst <= 0)
        {
            health--;
            thirst = 0;
        }
        
        if(hunger <= 0)
        {
            health--;
            hunger = 0;
        }
        
        score++;
    }
    
    string getStats() const 
    {
        stringstream ss;
        ss.str(""); // Clear the stringstream
        ss.clear(); // Clear any error flags
        ss  << "============\n"
            << "Health: " << health << endl 
            << "Hunger: " << hunger << endl 
            << "Thirst: " << thirst << endl
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const 
    {
        return health > 0;
    }
    
    void modifyThirst(int val) //called it modify because there is one land that decreases our thirst
    {
        thirst+=val;
        if(thirst > MAX_THIRST) thirst = MAX_THIRST;
        else if (thirst < 0) thirst = 0;
    }
    
    void increaseHunger(int val)
    {
        hunger += val;
        if(hunger > MAX_HUNGER) hunger = MAX_HUNGER;
    }
    void increaseHealth(int val)
    {
        health+=val;
        if (health > MAX_HEALTH) health = MAX_HEALTH;
    }
    int x, y;
    private:
        int health, hunger, thirst, score;

};

/*This is a base class for different types of lands. 
* Each land would have two methods that it would inherit from the base class land. 
* getDescription is used to display to the user what the land does.
* visit is used to make the land logic run which affects the whole game.
*/
class Land 
{
    public:
        virtual string getDescription() = 0;
        virtual string visit(Player& p) = 0;
};

class Forest : public Land 
{
    public:
        string getDescription()
        {
            return "a densely wooded forest.";
        }
        
        string visit(Player& p)
        {
            int randomNum = rand() % 100;
            
            if(randomNum > 74)
            {
                p.takeDamage(1);
                return "You were attacked by a bear while foraging for berries.";
            } 
            else 
            {
                p.increaseHunger(1);
                return "You forage for berries in the woods and eat a few.";
            }
        }
};

class Lake : public Land 
{
    public:
        string getDescription()
        {
            return "a clear sparkling lake.";
        }
        
        string visit(Player& p)
        {
            p.modifyThirst(2);
            return "You visit the lake and drink its clean water";
        }
};
class Hospital: public Land 
{
    public: 
        string getDescription() 
        {
            return ("a hospital and it will restore your health when you take the medicine");
        }
        string visit(Player & p) 
        {
            p.increaseHealth(MAX_HEALTH);// maximize the health
            return ("Your health is maximized"); 
        }

};
class IcedLand: public Land 
{
    public: 
        string getDescription() 
        {
            return ("an Iced land and it will decrease your health by 1");
        }
        string visit(Player & p) 
        {
            p.takeDamage(1); // decrement health by 1
            return "You cold";
        }

};
class Farm : public Land{
    public: 
        string getDescription()
        {
            return ("a farm and it will increase your hunger by 1"); 
            
        }
        string visit(Player&p)
        {
            p.increaseHunger(1); 
            return ("Your hunger was increased by 1");
        }
};
class Camp: public Land
{
    public: 
        string getDescription()
        {
            return ("a camp and it will increase your health and hunger by 1"); 
        }
        string visit(Player &p )
        {
            p.increaseHunger(1);
            p.modifyThirst(1);
            return ("Your hunger and thirst were increased by 1"); 
        }
};
class BasketBallField: public Land
{
    public: 
        string getDescription()
        {
            return ("a basket ball field which will decrease your thirst by 2"); 
        }
        string visit(Player&p)
        {
            p.modifyThirst(-2); 
            return ("Your thirst was decreased by 2");
        }
};
class HauntedHouse: public Land 
{
    public: 
        stringstream sss;
        int randomVarToPickTheQuestion;
        string getDescription() {
            sss.str(""); // Clear the stringstream
            sss.clear(); // Clear any error flags
            randomVarToPickTheQuestion = (rand() % 100); // This random variable controls the challenge in the haunted house
    
            if (randomVarToPickTheQuestion < 25) 
            { // Math problem
                sss << "a haunted house and in order to survive through here you need to solve the following Maths problem\n";
                if (randomVarToPickTheQuestion < 13) 
                { // 1st question
                    sss << "10 + 20 * 30 + 50 / 70";
                } 
                else 
                { // 2nd question
                    sss << "100000 - 10"; // Corrected the problem (10^2 * 10^3 - 10)
                }
            } 
            else if (randomVarToPickTheQuestion < 50) 
            { // Riddle
                sss << "a haunted house and in order to survive through here you need to solve the following riddle (ALL CAPS)\n";
                if (randomVarToPickTheQuestion < 38) 
                { // 1st riddle
                    sss << "What can run but can't walk?";
                } 
                else 
                { // 2nd riddle
                    sss << "What starts with T, is filled with T, and ends with T?";
                }
            } 
            else if (randomVarToPickTheQuestion < 75) 
            { // Historical question
                sss << "a haunted house and in order to survive through here you need to answer the following history questions\n";
                if (randomVarToPickTheQuestion < 63) 
                { // 1st question
                    sss << "Who built the pyramids?\n1- Ancient Egyptians\n2- Ancient Romans\n3- Ottomans\n4- Mongols";
                } 
                else 
                { // 2nd question
                    sss << "What was the name of the Egyptian president in 1973?\n1- Anwar El Sadat\n2- Gamal Abdel Nasser\n3- Hosni Mubarak\n4- Mohamed Naguib";
                }
            } 
            else 
            { // General question
                sss << "a haunted house and in order to survive through here you need to answer the following questions (numbers or ALL CAPS)\n";
                if (randomVarToPickTheQuestion < 88) 
                { // 1st question
                    sss << "How many states are in the United States?";
                } 
                else 
                { // 2nd question
                    sss << "How many continents are there in the world?";
                }
            }
            return sss.str();
        }
    string visit(Player & p) 
    {
        string input; //takes the input for the mathematical questions
        cout<<"Enter your answer>>";
        cin >> input;
        if (randomVarToPickTheQuestion < 25) 
        {
            if (randomVarToPickTheQuestion < 13) 
            {
                if (input == "610" || input == "611") 
                { // this is the right answer for the first challenge 
                    return ("That's correct, Great job");
                } 
                else 
                {
                    p.takeDamage(1);
                    return ("That's incorrect, your health was decreased by 1");
                }
            } 
            else 
            {
                if (input == "0") 
                {
                    return ("That's correct, Great job");
                } 
                else 
                {
                    p.takeDamage(1);
                    return ("That's incorrect, your health was decreased by 1");
                }
            }
            
        } 
        else if (randomVarToPickTheQuestion < 50) 
        { 
            if (randomVarToPickTheQuestion < 38) 
            {
                if (input == "RIVER" || input == "THE RIVER") 
                { // This is the right answer
                    return ("That's correct, Great job");
                } 
                else 
                { // if he answered incorrectly 
                    p.takeDamage(1);// decrement health by 1 
                    return ("That's incorrect, your health was decreases by 1");
                }
            } 
            else 
            {
                if (input == "TEAPOT" || input == "THE TEAPOT") 
                { 
                    return ("That's correct, Great job");
                } 
                else 
                {
                    p.takeDamage(1);;
                    return ("That's incorrect, your health was decreased by 1");
                }
            }
            
        } 
        else if (randomVarToPickTheQuestion < 75) 
        {
            if (randomVarToPickTheQuestion < 63) 
            {
                if (input == "1") 
                {
                    return ("That's correct, Great job");
                } 
                else 
                {
                    p.takeDamage(1);;
                    return ("That's incorrect, your health was decreased by 1");
                }
            }
            if (input == "1") 
            {

                return ("That's correct, Great job");
            } 
            else 
            {
                p.takeDamage(1);;
                return ("That's incorrect, your health was decreased by 1");
            }
            
        } 
        else 
        {
            if (randomVarToPickTheQuestion < 88) 
            {
                if (input == "50" || input == "FIFTY") 
                {
                    return ("That's correct, Great job");
                } 
                else 
                {
                    p.takeDamage(1);
                    return ("That's incorrect, your health was decreased by 1");
                }
            } 
            else 
            {
                if (input == "7" || input == "SEVEN") 
                {
                    return ("That's correct, Great job");
                } 
                else 
                {
                    p.takeDamage(1);;
                    return ("That's incorrect, your health was decreased by 1");
                }
            }
        }
    }

};
class LivesShop: public Land 
{
    public: string getDescription() 
    {
        return ("a lives shop and it will increase your health by 1");
    }
    string visit(Player & p) 
    {
        p.increaseHealth(MAX_HEALTH); 
        return ("Your health is maximized"); 
    }

};
class GroceryStore: public Land 
{ 

    public: string getDescription() 
    {
        return ("a grocery store and it will restore your hunger to the max");
    }
    string visit(Player & p) 
    {
        p.increaseHunger(MAX_HUNGER); // maximize hunger from the grocery store
        return ("Your hunger is stored to max"); 
    }
};

void populateMap(Land* map[MAP_SIZE][MAP_SIZE]){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            int randomNum = rand() % 9;
            switch(randomNum){
                case 0: 
                    map[i][j] = new Forest;
                    break;
                case 1: 
                    map[i][j] = new Lake;
                    break;
                case 2: 
                    map[i][j] = new HauntedHouse;
                    break;
                case 3: 
                    map[i][j] = new LivesShop;
                    break;
                case 4: 
                    map[i][j] = new GroceryStore;
                    break;
                case 5: 
                    map[i][j] = new IcedLand; 
                    break;
                case 6: 
                    map[i][j] = new Hospital;
                break;
                case 7: 
                    map[i][j] = new Farm;
                    break; 
                case 8: 
                    map[i][j] = new Camp; 
                    break;
                default:
                    cout << "Invalid land type selected\n"; //Will never get there, but to clear compiler warnings.
                    break;
            }
        }
    }
}


// Function to deallocate memory for the map to avoid memory leaks
void cleanMap(Land* map[MAP_SIZE][MAP_SIZE])
{
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            delete map[i][j]; 
            map[i][j] = nullptr; 
        }
    }
}


int main(){
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
            case 'N':
            case 'n':
                player.y = player.y - 1;
            break;
            case 'E':
            case 'e':
                player.x = player.x + 1;
            break;
            case 'S':
            case 's':   
                player.y = player.y + 1;
            break;
            case 'W':
            case 'w':    
                player.x = player.x - 1;
            break;
            default:
                cout<<"Wrong input, please enter N,W,E,S\n";
                userInput = 'x';  
            break;
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