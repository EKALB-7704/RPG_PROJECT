//code for simple main menu function 
/*#include <iostream>
#include <string>
#include <limits>
#include "Character_create.h"
using namespace std;
using std::string;

int main() {
    char confirmation;
    int choice;
    Character player;
   
   
    cout << "welcome to the main menu" << endl;

    
    cout << "select an option:" << endl;
    cout << "(1) Create Character" << endl;
    cout << "(2) Load Character" << endl;
    cout << "(3) Exit" << endl;
    cin >> choice;

    bool running = true;
    while (running=true) {
             switch (choice) {

            case 1: choice = 1;
                cout << "Creating Character..." << endl;
                 player.Create();
                break;

            case 2: choice = 2;
                cout << "Loading Character..." << endl;
                player.Character_Readback();
                player.stats_readback();
                break;

            case 3: choice = 3;
                cout << "Exiting..." << endl;
                running = false;
                return 0;
                
            default:
                cout << "Invalid input." << endl;
                continue;
            }
        }
    
    
return 0;
}
*/