#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;

class Monster {
public:
    string name;
    int hp;
    int attack;
    int rewardExp;
    int rewardGold;

    Monster(string n, int h, int a, int xp, int g);
};

Monster getRandomMonster();

class Battle;{
public:
    void engage(Player &player, Monster &monster);
    void skeleton();
    void goblin();
    void orc();
    void enemy();
    void boss();

}

#endif
