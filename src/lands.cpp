#include <cstdlib>
#include <string>
#include <sstream>
#include "lands.h"




string Forest::getDescription()
{
    return "a densely wooded forest.";
}

string Forest::visit(Player& p)
{
    int randomNum = rand() % 100;
    if (randomNum > 74)
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

string Lake::getDescription()
{
    return "a clear sparkling lake.";
}

string Lake::visit(Player& p)
{
    p.modifyThirst(2);
    return "You visit the lake and drink its clean water.";
}

string Hospital::getDescription()
{
    return "a hospital that restores your health.";
}

string Hospital::visit(Player& p)
{
    p.increaseHealth(MAX_HEALTH);
    return "Your health is fully restored.";
}

string IcedLand::getDescription() 
{
    return ("an Iced land and it will decrease your health by 1");
}
string IcedLand::visit(Player & p) 
{
    p.takeDamage(1); // decrement health by 1
    return "You cold";
}
string Farm::getDescription()
{
    return ("a farm and it will increase your hunger by 1"); 
    
}
string Farm::visit(Player&p)
{
    p.increaseHunger(1); 
    return ("Your hunger was increased by 1");
}
string Camp::getDescription()
{
    return ("a camp and it will increase your health and hunger by 1"); 
}

string Camp::visit(Player &p )
{
    p.increaseHunger(1);
    p.modifyThirst(1);
    return ("Your hunger and thirst were increased by 1"); 
}
string BasketBallField::getDescription()
{
    return ("a basket ball field which will decrease your thirst by 2"); 
}
string BasketBallField::visit(Player&p)
{
    p.modifyThirst(-2); 
    return ("Your thirst was decreased by 2");
}

string HauntedHouse::getDescription() 
{
    stringstream sss;
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
string HauntedHouse::visit(Player & p) 
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
string LivesShop::getDescription() 
{
    return ("a lives shop and it will increase your health by 1");
}
string LivesShop::visit(Player & p) 
{
    p.increaseHealth(MAX_HEALTH); 
    return ("Your health is maximized"); 
}

string GroceryStore::getDescription() 
{
    return ("a grocery store and it will restore your hunger to the max");
}
string GroceryStore::visit(Player & p) 
{
    p.increaseHunger(MAX_HUNGER); // maximize hunger from the grocery store
    return ("Your hunger is stored to max"); 
}


