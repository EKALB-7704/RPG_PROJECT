#include "Area.h"
#include <iostream>
#include <string>
#include <Character_create.h>
using namespace std;

void Area::travel()
{
    
    std::cout << "Where would you like to go? " << endl;
    std::cout << "[SWAMP]  [FOREST]  [DESERT]  [MOUNTAIN]" << endl;
    std::cin >> destination;
    location = destination;
    std::cout << "Travelling to " << destination << endl;
}

void Area::current_area()
{
    cout << "you are currently in " << "[" << location << "]" << endl; 

}
void Area::starting_location(Character& character)
{
    switch (character.race) {
        case 1:
            location = "SWAMP";
            break;
        case 2:
            location = "FOREST";
            break;
        case 3:
            location = "MOUNTAINS";
            break;
        case 4:
            location = "VILLAGE";
            break;
    }
    cout << "Your starting location is " << location << endl;
}
