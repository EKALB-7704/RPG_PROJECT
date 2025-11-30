#include "Game.h"
#include "Area.h"
#include "Character_create.h"
#include "Encounters.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x;
    string action = "action";
    bool Program_running = true; // bool to create loops to run always while the program is running
    bool Create_character;


    
    Game game;
    Area area;
    Character character;
    Encounters encounters;
   

    //game.Run();

    cout << "\nGame startup complete! " << endl;

    character.create_prompt();
 
  



    while(Program_running = true)
    {
        //encounters.enemy_create();
        encounters.random_encounter();
        

        cout << "What would you like to do? " << endl;
        cout << "[ATTACK]\n[HEAL]\n[TRAVEL]\n[STATS]\n";
        std::cin >> action;

        if (action == "ATTACK")
        {
            cout << "You attacked!";
        }
        else if (action == "HEAL")
        {
            cout << "You healed";
        }
        else if (action == "TRAVEL")
        {
            area.current_area();
            area.travel();
        }
        else if (action == "STATS")
        {
            character.stats_readback();
        }
        else 
        {
            cout << "That was not an option!";
            
        }
    }
    




    std::cin >> x;



    
    

   
    
    return 0;
}

