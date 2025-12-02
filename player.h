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

class Character
{
    // All Void Functions Are Capitalized
    private:
        void Age();
        void Gender();
        void Race();
        void Name();
        void Class_();

    int level= 0;
    int base_health= 100;
    int base_strength = 10;
    int base_defense = 10;
    int gold = 0;

    

    public:
    Character() = default;  // Default constructor
    void Create();
    void Character_Readback();
    void starting_stats();
    void stats_readback();
    void create_prompt();

    
    int age;
    int Class;
    string name;
    string gender;
    string Create_choice;
    int race;

  
    char confirmation;
     int m,M,f,F;
};

#endif
