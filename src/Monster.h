#ifndef MONSTER_H
#define MONSTER_H
#include <thread>
#include <chrono>
#include <string>

constexpr int kBossLevel = 5;

class Monster {

private:
    bool isBoss = false;
    

public:
    std::string name;
    int hp;
    int attack;
    int rewardExp;
    int rewardGold;

    

    bool getIsBoss() const { return isBoss; }

    Monster(std::string n, int h, int a, int xp, int g, bool boss = false);

    void Display_Monster(const std::string &location) const;





};

Monster returnOpponent(int &level);

Monster getBoss();

Monster getRandomMonster();


#endif
