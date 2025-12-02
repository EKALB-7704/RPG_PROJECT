#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;




class Player
{
    // All Void Functions Are Capitalized
    private:
    void Age();
    void Gender();
    void Race();
    void Name();
    void Class_();

    

    

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
    int current_strength, current_defense;


    Player(string n);

    void heal();
    int specialAttack();
    void gainExp(int amount);
    Player() = default;  // Default constructor
    void Create();
    void Character_Readback();
    void starting_stats();
    void stats_readback();
    void create_prompt();

    
    int base_health= 100;
    int base_strength = 10;
    int base_defense = 10;
    
    int age;
    int Class;
    
    string gender;
    string Create_choice;
    int race;

  
    char confirmation;
     int m,M,f,F;
};

#endif
