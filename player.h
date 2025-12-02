#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    string name;
    int hp, maxHP;
    int attack;
    int level;
    int exp;
    int potions;
    int gold;
    int maxStamina;
    int stamina;

    Player(string n);

    void heal();
    int specialAttack();
    void gainExp(int amount);
};

#endif
