#include "Area.h"
#include <iostream>
#include <string>
#include "player.h"
using namespace std;



void Area::current_area()
{
    cout << "you are currently in " << "[" << location << "]" << endl; 

}
void Area::travel(Player &player)
{
    cout << "Where would you like to go?" << endl;
    cout << "1. FOREST" << endl;
    cout << "2. PLAINS" << endl;
    cout << "3. MOUNTAINS" << endl;
    cout << "4. SWAMP" << endl;
    cout << "Enter the name of your destination: ";
    cin >> destination;
    if (destination == 1)
        location = "FOREST";
    else if (destination == 2)
        location = "PLAINS";
    else if (destination == 3)
        location = "MOUNTAINS";
    else if (destination == 4)
        location = "SWAMP";
    else
    {
        cout << "Invalid destination. Staying in current location." << endl;
      
    }

    cout << "You have traveled to the " << location << "." << endl;
    ;
}


