#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "Monster.h"
#include "save_system.h"
#include "Store.h"
#include "Area.h"
using namespace std;

/*Checklist of shit left to do.
idiot-proof character create menu DONE
fix health scale -paul DONE
fix special attack -paul DONE
fix stats loading from save issue -paul DONE
fix load save when no save exists issue - paul DONE
fix max health display -paul DONE
add new enemies -anyone
adjust odds for enemies to spawn -anyone
make boss summon function - callum DONES
write document for game path to be presented.

after everything here is done do thorourgh check
to remove any unnecessary code/files and ensure 
game loop is fully functional

*/

int a=1;// integer used for empty area flag
bool in_battle;


//Declare battle and map functions
bool battle(Player &player);

void showMap();


/* =====================
       COMBAT
   ===================== */

bool battle(Player &player) {
    //Pull random monster to fight and display it

    Monster m = returnOpponent(player.level);
    m.Display_Monster();
    


    cout << "\n A wild " << m.name << " appears!\n";

    
    //Keep combat loop running while both player 
    //and monster are alive (health > 0)
    while (player.current_health > 0 && m.hp > 0) 
    {
        //Display monster and player current stats(Health,stamina etc.)
        cout << "\nYour HP: " << player.current_health << "/" << player.maxHP << "\n" << "Your Stamina: "<< player.stamina << "/" << player.maxStamina << "\n";
        cout << m.name << " HP: " << m.hp << "\n";
        cout << "Potions: " << player.potion << "\n";

        //Display action options and take in usier input
        cout << "\nChoose action:\n";
        cout << "1. Attack\n";
        cout << "2. Heal\n";
        cout << "3. Special Attack\n";
        cout << "> ";

        int choice;
        cin >> choice;


        if (choice == 1) // 1 = attack
        {
           
            //Do calc for damage dealt to monster
            int dmg = rand() % player.current_attack + 1;
            m.Display_Monster();
            cout << "You deal " << dmg << " damage.\n";
            m.hp -= dmg;
        }
        else if (choice == 2) // 2 = consume potion to heal
        {
            //Run heal function 
            m.Display_Monster();
            player.heal();
        }
        else if (choice == 3) // 3 = special attack
        {
            //Run special attack function
            m.Display_Monster();
            int dmg = player.specialAttack();
            m.hp -= dmg;
        }
        
        else 
        {
            //If user input is not one of the assigned options output the following
            m.Display_Monster();
            cout << "Invalid choice! you stumble!\n";
        }

        //Monster damage dealt to player calc
        if (m.hp > 0) {
            int dmg = rand() % m.attack + 1;
            cout << m.name << " hits you for " << dmg << "!\n";
            int true_dmg = (dmg - (player.current_defence % 4));
            if (true_dmg > 0)
            {
                true_dmg = 0;
            }
            player.current_health -= true_dmg ;
        }
    
       
    }

    //conditon check to see if player is dead
    if (player.current_health <= 0) 
    {
        cout << "\n You were defeated...\n";
        return false;
    }
    //Victory message and reward calc for defeating a mosnter
    cout << "\n You defeated the " << m.name << "!\n";
    player.gainExp(m.rewardExp);
    player.gold += m.rewardGold;
    player.kill_count++;
    cout << "You found " << m.rewardGold << " gold!\n";

    return true;
}


/* =====================
       TOWN / MAP
   ===================== */

void showMap() //map function
{
    cout << "\n--- MAP ---\n";
    cout << "1. Fight \n";
    cout << "2. Town (Shop)\n";
    cout << "3. Stats\n";
    cout << "4. travel\n";
    cout << "5. Save Game\n";
    cout << "6. Quit Game\n";
}


/* =====================
           MAIN
   ===================== */

int main() // set main loop
{

    srand(time(0));
    store store; 
    Area area;

    Player player("temp");  // temporary until load or new game
     cout << "                    +##*####****######*####                    " << endl;
    cout << "               +***=+++====------------===+++*****               " << endl;             
    cout << "            *#==---------------------------=======+*#+           " << endl;
    cout << "      #**=-------:::::::::::::::::::::::::::-----------=+***     " << endl;
    cout << "  *##*++++=+=---:::----:::::::::::----:::::::::----==++===+*%*   " << endl;
    cout << "  *%#*++==+#*+==-------------::::------::::::----===+*#+++**%*   " << endl;
    cout << " ++#*+++=++###**+++==---==---------------:---==++***###*+++*#++  " << endl;
    cout << " ##*++===*#%%%%%##*++===++===--------==+=-===***##%%%%%#*=+++##= " << endl;
    cout << " ##+++===*%%%%%%%%##*+==+==++==----==++===+**###%%%%%%%#*==++##= " << endl;
    cout << " ##++==+#%%%%%%%%%%%%#*+++===++=--=++===++##%%%%%%%%%%%%%#+=+*#= " << endl;
    cout << " ##++==+###%###%%%%%%%%%#*++===+=++===++##%%%%%%%%%###%###===*#= " << endl;
    cout << "#*#++=-+########%%%%%%%%%%#**========**#%%%%%%%%%%########===*#*#" << endl;
    cout << "%*+===-=+######%%%%%%%%%%%%##--:==:-=##%%%%%%%%%%%%#####*+===++#%" << endl;
    cout << "%*+++==--=+#%%%%%%%%%%%%%%#+=--=++=--=*#%%%%%%%%%%%%%##+=--==++#%" << endl;
    cout << "%*++=-:---=##%%%%%%%%%%%#*====++##=---==*#%%%%%%%%%%%#*=----==+#%" << endl;
    cout << "%*+=--::---===*#######+===-==+*#%#++==--===+#####*#*===-----==+##" << endl;
    cout << "%*+=-::::--------=====-----==+#%###**+==---------::::------==*#= " << endl;
    cout << "#*+===--:::--======-------:==*#%#####+++=-----====------=====*#= " << endl;
    cout << " ##=========+++++++==-----:=+#%######====----===++==========+##= " << endl;
    cout << " ##++++++++++****++++==----*######%###*----==+++++++++++++++*##= " << endl;
    cout << "  *####**++***++===---:::--*##%%%%%%%%*----===+++****+++*%***##= " << endl;
    cout << "     +##%***#%++==--::::::--=###=+##*=-::---==+++++****######+   " << endl;
    cout << "       +##%%%%%#*=--::---::::---::----:-:::--=+****#%%#          " << endl;
    cout << "         #%###%%%#+--------+++++++++++=-:::--*#%%%##%#*          " << endl;
    cout << "         ++###*#%*+----=***##===##===%#**+-=*%%%%###%*           " << endl;
    cout << "          =#%%##%+=#*=*#%*-##-:-#*::-#*-*%#+-#%%%####*           " << endl;
    cout << "          =####%%%%%%#%#::-##=--##--=%*-:-%*=#%%%%%*             " << endl;
    cout << "          =#####%%%%*:*#---#%%%%%%%%%%*--=%%%%%###%*             " << endl;
    cout << "           **###*#%%#+#%%#+#%%%%%%%%%%#+##+*%#####%*             " << endl;
    cout << "            *%####*%%%++%#+##=*%+=+#%+=+##-+%#*####*             " << endl;
    cout << "            ++#%%#*+*%=-%*-##:+%---*#-=*#%***#####               " << endl;
    cout << "              #%##*+=-*#%##############%++##*#%%+                " << endl;
    cout << "              *#**+===-=#*------------+#=-+**##%**               " << endl;
    cout << "                 **+++=-:----------------===++*##               " << endl;
    cout << "                   ***##*--::::::--::::-=++###**                 " << endl;
    cout << "                      ##**#*=----------+##**#*                    " << endl;
    cout << "                           *##########*                         " << endl;
    cout << "WELCOME TO SKELETON QUEST!\n";
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "> ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        player.Create();
    }
    else if (choice == 2) {
        if (!loadGame(player)) {
            cout << "No save file found. Starting new game.\n";
            player.Create();
        } else {
            cout << "Game loaded! Welcome back, " << player.name << ".\n";
        }
    }
    else {
        cout << "Invalid choice â€” starting new game.\n";
        cout << "Enter your name: ";
        cin >> player.name;
    }

    cout << "\nYour adventure begins...\n";

    while (true) {
        showMap();

        cout << "\nChoose a location: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if(a>0){
                a--;
                if (!battle(player)) {
                    cout << "\nGAME OVER.\n";
                    break;
                }
            }
            else{
                cout << "You have already defeated the enemy here. Travel to a new location to find more enemies.\n";
            }
        }
        else if (choice == 2) {
            store.town(player);
        }
        else if (choice == 3)
        {
            player.stats_readback();
        }
        else if (choice == 5) 
        {
            if (saveGame(player))
                cout << "Game saved!\n";
            else
                cout << "Error: Could not save.\n";
        }
        else if (choice == 6) {
        cout << "Thanks for playing!\n";
        break;
        }
        else if (choice ==4)
        {
           Area area;
            area.travel(player);
            a++;
        }
        else {
            cout << "Invalid choice.\n";
        }

    }

    return 0;
}


