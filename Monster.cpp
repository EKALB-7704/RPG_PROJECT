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

Monster returnOpponent(int &level)
{
    if (level >= 3)
    {
        return getBoss();
    }
    
    
    return getRandomMonster();
    
}

Monster getBoss()
{
    return Monster("Skeleton king", 200, 20, 100, 4000);
}

Monster getRandomMonster() {
    int r = rand() % 10;

    if (r >= 0 && r <= 3 ) return Monster("Skeleton Minion", 30, 4, 10, 15);
    if (r > 4 && r <= 6) return Monster("Skeleton Soldier", 35, 6, 15, 20);
    if (r > 7 && r <= 8) return Monster("Skeleton Knight", 45, 10, 25, 30);
    return Monster("Skeleton Giant", 55, 7, 30, 40);
 
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
