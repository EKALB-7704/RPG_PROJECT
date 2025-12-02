#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void moveCursorUp(int n) {
    cout << "\033[" << n << "A";
}
void clearLine() {
    cout << "\33[2K\r";
}
void battle() {
    int current_attack = 15;
    int potion = 1;
    int enemy_health = 30;
    int current_health = 50;
    int current_defence = 5;

    while (enemy_health > 0 && current_health > 0) {

        int enemy_damage = 10 - current_defence;
        if (enemy_damage < 0) enemy_damage = 0;

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
