#ifndef MONSTER_H
#define MONSTER_H
#include <thread>
#include <chrono>
#include <string>

constexpr int kBossLevel = 5;

class Monster {

public:
    std::string name;
    bool isBoss = false;
    int hp;
    int attack;
    int rewardExp;
    int rewardGold;

    

    

    Monster(std::string n, int h, int a, int xp, int g);

    void Display_Monster(const std::string &location) const;





};

Monster returnOpponent(int &level);

Monster getBoss();

Monster getRandomMonster();


#endif
