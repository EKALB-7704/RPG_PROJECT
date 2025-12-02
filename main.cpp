#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "Monster.h"
#include "save_system.h"
#include "Store.h"
using namespace std;







bool battle(Player &player);
//void town(Player &player);
void showMap();


/* =====================
       COMBAT
   ===================== */

bool battle(Player &player) {
    Monster m = getRandomMonster();
    


    cout << "\n A wild " << m.name << " appears!\n";

    m.Display_Monster();

    while (player.hp > 0 && m.hp > 0) {
        cout << "\nYour HP: " << player.hp << "/" << player.maxHP << "\n" << "Your Stamina: "<< player.stamina << "/" << player.maxStamina << "\n";
        cout << m.name << " HP: " << m.hp << "\n";
        cout << "Potions: " << player.potions << "\n";

        cout << "\nChoose action:\n";
        cout << "1. Attack\n";
        cout << "2. Heal\n";
        cout << "3. Special Attack\n";
        cout << "> ";

        int choice;
        cin >> choice;


        if (choice == 1) {
            int dmg = rand() % player.attack + 1;
            cout << "You deal " << dmg << " damage.\n";
            m.hp -= dmg;
        }
        else if (choice == 2) {
            player.heal();
        }
        else if (choice == 3) {
            int dmg = player.specialAttack();
            m.hp -= dmg;
        }
        else {
            cout << "Invalid choice!\n";
        }

        if (m.hp > 0) {
            int dmg = rand() % m.attack + 1;
            cout << m.name << " hits you for " << dmg << "!\n";
            player.hp -= dmg;
        }
    
        this_thread::sleep_for(chrono::milliseconds(800));

        const int linesPrinted = 32;

        m.moveCursorUp(linesPrinted);
        for (int i = 0; i < linesPrinted; i++) 
        {
            m.clearLine();
            cout << endl;
        }
        m.moveCursorUp(linesPrinted);
    }

    if (player.hp <= 0) {
        cout << "\n You were defeated...\n";
        return false;
    }

    cout << "\n You defeated the " << m.name << "!\n";
    player.gainExp(m.rewardExp);
    player.gold += m.rewardGold;
    cout << "You found " << m.rewardGold << " gold!\n";

    return true;
}


/* =====================
       TOWN / MAP
   ===================== */

void showMap() {
    cout << "\n--- MAP ---\n";
    cout << "1. Forest (Monsters)\n";
    cout << "2. Town (Shop)\n";
    cout << "3. Save Game\n";
    cout << "4. Quit Game\n";
}


/* =====================
           MAIN
   ===================== */

int main() {
  srand(time(0));
    store store;

    Player player("temp");  // temporary until load or new game

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
            cout << "Enter your name: ";
            cin >> player.name;
        } else {
            cout << "Game loaded! Welcome back, " << player.name << ".\n";
        }
    }
    else {
        cout << "Invalid choice — starting new game.\n";
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
            if (!battle(player)) {
                cout << "\nGAME OVER.\n";
                break;
            }
        }
        else if (choice == 2) {
            store.town(player);
        }
        else if (choice == 3) 
        {
            if (saveGame(player))
                cout << "Game saved!\n";
            else
                cout << "Error: Could not save.\n";
        }
        else if (choice == 4) {
        cout << "Thanks for playing!\n";
        break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

