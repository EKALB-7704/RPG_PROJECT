#include "Monster.h"
#include "player.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
#include <string>


Monster::Monster(string n, int h, int a, int xp, int g) {
    name = n;
    hp = h;
    attack = a;
    rewardExp = xp;
    rewardGold = g;
}

Monster getRandomMonster() {
    int r = rand() % 3;

    if (r == 0) return Monster("Goblin", 20, 5, 10, 5);
    if (r == 1) return Monster("Skeleton", 25, 6, 15, 8);
    return Monster("Orc", 30, 8, 20, 12);
 
}
void moveCursorUp(int n) {
    cout << "\033[" << n << "A";
}
void clearLine() {
    cout << "\33[2K\r";
}
void battle() {

    while (Monster.hp > 0 && player.hp > 0) {

        int enemy_damage = 10 - player.defence;
        if (Monster.hp < 0) enemy_damage = 0;

        cout << "==========================================================================================================\n";
        cout << "                                             <<current_location>>\n";
        cout << "                                                <<Enemy_type>>\n";
        cout << "                   " << enemy_health << "                                        " << enemy_damage << "\n";
        cout << "==========================================================================================================\n";
        cout << "\n";
        cout << "                                                      .-.\n";
        cout << "                                                     (o.o)\n";
        cout << "                                                      |=|\n";
        cout << "                                                     __|__\n";
        cout << "                                                   //.=|=.\\\\\n";
        cout << "                                                  // .=|=. \\\\\n";
        cout << "                                                  \\\\ .=|=. //\n";
        cout << "                                                   \\\\(_=_)//\n";
        cout << "                                                    (:| |:)\n";
        cout << "                                                     || ||\n";
        cout << "                                                     () ()\n";
        cout << "                                                     || ||\n";
        cout << "                                                     || ||\n";
        cout << "                                                    ==' '==\n";
        cout << "\n";
        cout << "==========================================================================================================\n";
        cout << "             (" << current_health << ")HP                                     (" << current_attack << ")ATK    (" << current_defence << ")DEF        (" << potion << ")Potions\n";
        cout << "==========================================================================================================\n";
        cout << "1) Attack\n";
        cout << "2) Heal\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            enemy_health -= current_attack;  
            cout << "\nYou attack for " << current_attack << "!\n";
        } 
        else if (choice == 2) {
            if (potion > 0) {
                potion--;
                current_health += 20; // Correct healing amount
                cout << "\nYou heal for 20!\n";
            } else {
                cout << "\nNo potions left!\n";
            }
        }

        if (enemy_health > 0) {
            current_health -= enemy_damage;
            cout << "Enemy hits you for " << enemy_damage << "!\n";
        }

        this_thread::sleep_for(chrono::milliseconds(800));

        const int linesPrinted = 32;

        moveCursorUp(linesPrinted);
        for (int i = 0; i < linesPrinted; i++) {
            clearLine();
            cout << endl;
        }
        moveCursorUp(linesPrinted);
    }

    if (current_health <= 0)
        cout << "\nYou died!\n";
    else
        cout << "\nEnemy defeated!\n";

    
}
    

