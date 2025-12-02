#include "Monster.h"
#include <cstdlib>

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
