#ifndef MONSTER_H
#define MONSTER_H
#include <thread>
#include <chrono>
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

    void Display_Monster();





};

Monster returnOpponent(int &level);

Monster getBoss();

Monster getRandomMonster();


#endif
