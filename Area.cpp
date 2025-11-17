#include "Area.h"
#include <iostream>
#include <string>

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
