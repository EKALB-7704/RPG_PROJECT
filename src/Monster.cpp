#include "Monster.h"
#include "Player.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>


#include <iostream>




Monster::Monster(std::string n, int h, int a, int xp, int g, bool boss) {
    name = n;
    hp = h;
    attack = a;
    rewardExp = xp;
    rewardGold = g;
    isBoss = boss;
}

Monster returnOpponent(int &level)
{
    if (level >= kBossLevel)
    {
        return getBoss();
    }
    
    
    return getRandomMonster();
    
}

Monster getBoss()
{
    return Monster("Skeleton King", 200, 20, 100, 4000, true);
}

Monster getRandomMonster() {
    int r = rand() % 10;

    if (r <= 3) return Monster("Skeleton Minion", 30, 4, 10, 15);
    if (r <= 6) return Monster("Skeleton Soldier", 35, 6, 15, 20);
    if (r <= 8) return Monster("Skeleton Knight", 45, 10, 25, 30);
    return Monster("Skeleton Giant", 55, 7, 30, 40);
 
}

void Monster::Display_Monster(const std::string &location) const
{
        const std::size_t width = 106;  // width of the ==== banner
        auto centred = [width](const std::string &text) {
            std::size_t pad = text.size() < width ? (width - text.size()) / 2 : 0;
            return std::string(pad, ' ') + text;
        };

        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl ;
        std::cout << "==========================================================================================================\n";
        std::cout << centred("[" + location + "]") << '\n';
        std::cout << centred(name) << '\n';
        std::cout << "==========================================================================================================\n";
        std::cout << "\n";
        std::cout << "                                                      .-.\n";
        std::cout << "                                                     (o.o)\n";
        std::cout << "                                                      |=|\n";
        std::cout << "                                                     __|__\n";
        std::cout << "                                                   //.=|=.\\\\\n";
        std::cout << "                                                  // .=|=. \\\\\n";
        std::cout << "                                                  \\\\ .=|=. //\n";
        std::cout << "                                                   \\\\(_=_)//\n";
        std::cout << "                                                    (:| |:)\n";
        std::cout << "                                                     || ||\n";
        std::cout << "                                                     () ()\n";
        std::cout << "                                                     || ||\n";
        std::cout << "                                                     || ||\n";
        std::cout << "                                                    ==' '==\n";
        std::cout << "\n";
        std::cout << "==========================================================================================================\n";
        std::cout << "==========================================================================================================\n";
    

   

}
