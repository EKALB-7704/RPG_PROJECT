#include "Monster.h"
#include "player.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
#include <string>


#include <iostream>

using namespace std;

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

void Monster::Display_Monster()
{
        cout << "==========================================================================================================\n";
        cout << "                                             <<current_location>>\n";
        cout << "                                                <<Enemy_type>>\n";

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
        
        cout << "==========================================================================================================\n";
    

   

}

void Monster::moveCursorUp(int n) 
{
    cout << "\033[" << n << "A";
}
void Monster::clearLine() 
{
    cout << "\33[2K\r";
}
