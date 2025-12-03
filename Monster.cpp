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

    if (r == 0) return Monster("Skeleton Wolf", 20, 4, 10, 20);
    if (r == 1) return Monster("Skeleton", 25, 5, 15, 30);
    return Monster("Giant Skeleton", 30, 6, 15, 40);
 
}

void Monster::Display_Monster()
{
        cout << endl << endl << endl << endl << endl << endl << endl ;
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
