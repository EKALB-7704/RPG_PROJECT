#include "Game.h"
#include "Area.h"
#include "Character_create.h"
#include <iostream>
using namespace std;

int main()
{
    string x;
    string action;


    
    Game game;
    Area area;
    Character character;
   

    game.Run();

    cout << "\nGame startup complete! " << endl;

    character.create_prompt();
    character.character_readback();

    cout << "What would you like to do? " << endl;
    cout << "[ATTACK]\n[DEFEND]\n[TRAVEL]\n";
    cin >> action;

    if (action == "ATTACK")
    {
        cout << "You attacked!";
    }
    else if (action == "DEFEND")
    {
        cout << "You defended";
    }
    else if (action == "TRAVEL")
    {
        area.travel();
    }
    else 
    {
        cout << "That was not an option!";
        
    }
    




    cin >> x;



    
    

   
    
    return 0;
}

