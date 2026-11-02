
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "SaveSystem.h"
#include "Store.h"
#include "Area.h"
#include "Art.h"
#include "Input.h"
#include "Battle.h"


//Declare map function
void showMap();


/* =====================
       TOWN / MAP
   ===================== */

void showMap() //map function
{
    std::cout << "\n--- MAP ---\n";
    std::cout << "1. Fight \n";
    std::cout << "2. Town (Shop)\n";
    std::cout << "3. Stats\n";
    std::cout << "4. travel\n";
    std::cout << "5. Save Game\n";
    std::cout << "6. Quit Game\n";
}


/* =====================
           MAIN
   ===================== */

int main() // set main loop
{

    srand(time(0));
    store store; 
    Area area;
    Art main_art;

    Player player;

     
    main_art.Main_menu_skull();
    std::cout << "WELCOME TO SKELETON QUEST!\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Load Game\n";

    int choice = readInt("> ", 1, 2);

    if (choice == 1) {
        player.Create();
    }
    else if (choice == 2) {
        if (!loadGame(player)) {
            std::cout << "Starting a new game.\n";
            player.Create();
        } else {
            std::cout << "Game loaded! Welcome back, " << player.name << ".\n";
        }
    }
   

    std::cout << "\nYour adventure begins...\n";

    while (true) {
        showMap();

        switch (readInt("\nChoose an option: ", 1, 6)) {
            case 1:
                if (player.area_cleared) {
                    std::cout << "You have already defeated the enemy here. Travel to a new location to find more enemies.\n";
                    break;
                }
                switch (battle(player)) {
                    case BattleResult::Defeat:
                        std::cout << "\nGAME OVER.\n";
                        return 0;
                    case BattleResult::BossDefeated:
                        std::cout << "\nThe Skeleton King crumbles to dust. YOU WIN!\n";
                        return 0;
                    case BattleResult::Victory:
                        player.area_cleared = true;
                        break;
                }
                break;
            case 2:
                store.town(player);
                break;
            case 3:
                player.stats_readback();
                break;
            case 4:
                area.travel(player);
                break;
            case 5:
                if (saveGame(player))
                    std::cout << "Game saved!\n";
                else
                    std::cout << "Error: Could not save.\n";
                break;
            case 6:
                std::cout << "Thanks for playing!\n";
                return 0;
        }
    }
}
