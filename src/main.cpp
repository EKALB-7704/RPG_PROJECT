
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Monster.h"
#include "SaveSystem.h"
#include "Store.h"
#include "Area.h"
#include "Art.h"
#include "Input.h"


enum class BattleResult { Victory, Defeat, BossDefeated };




//Declare battle and map functions
BattleResult battle(Player &player);

void showMap();


/* =====================
       COMBAT
   ===================== */

BattleResult battle(Player &player) 
{

    //Pull random monster to fight and display it
    
    Monster enemy_m = returnOpponent(player.level);
    enemy_m.Display_Monster(player.location);
    
    
    


    std::cout << "\n A wild " << enemy_m.name << " appears!\n";

    
    //Keep combat loop running while both player 
    //and monster are alive (health > 0)
    while (player.current_health > 0 && enemy_m.hp > 0) 
    {
        
        //Display monster and player current stats(Health,stamina etc.)
        std::cout << "\nYour HP: " << player.current_health << "/" << player.maxHP << "\n" << "Your Stamina: "<< player.stamina << "/" << player.maxStamina << "\n";
        std::cout << enemy_m.name << " HP: " << enemy_m.hp << "\n";
        std::cout << "Potions: " << player.potion << "\n";

        //Display action options and take in user input
        std::cout << "\nChoose action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Heal\n";
        std::cout << "3. Special Attack\n";

        int choice = readInt("> ", 1, 3);

        if (choice == 1) // 1 = attack
        {
           
            //Do calc for damage dealt to monster
            int dmg = rand() % player.current_attack + 1;
            enemy_m.Display_Monster(player.location);
            std::cout << "You deal " << dmg << " damage.\n";
            enemy_m.hp -= dmg;
        }
        else if (choice == 2) // 2 = consume potion to heal
        {
            //Run heal function 
            enemy_m.Display_Monster(player.location);
            player.heal();
        }
        else if (choice == 3) // 3 = special attack
        {
            //Run special attack function
            enemy_m.Display_Monster(player.location);
            int dmg = player.specialAttack();
            enemy_m.hp -= dmg;
        }
        

        //Monster damage dealt to player calc
        if (enemy_m.hp > 0) {
            int dmg = rand() % enemy_m.attack + 1;
            std::cout << enemy_m.name << " hits you for " << dmg << "!\n";
            int true_dmg = (dmg - (player.current_defence / 6));
            if (true_dmg < 0)
            {
                true_dmg = 0;
            }
            player.current_health -= true_dmg ;
        }
    
       
    }

    //conditon check to see if player is dead
    if (player.current_health <= 0) 
    {
        std::cout << "\n You were defeated...\n";
        return BattleResult::Defeat;
    }
    //Victory message and reward calc for defeating a mosnter
    std::cout << "\n You defeated the " << enemy_m.name << "!\n";
    player.gainExp(enemy_m.rewardExp);
    player.gold += enemy_m.rewardGold;
    player.kill_count++;
    std::cout << "You found " << enemy_m.rewardGold << " gold!\n";

    return enemy_m.getIsBoss() ? BattleResult::BossDefeated : BattleResult::Victory;
}


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


