#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
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
    void quest();

    

    

    public:
    string name;
    int hp, maxHP;
    int level;
    int level_reference;
    int exp;
    int gold;
    int maxStamina;
    int stamina;
    
    
    int current_attack, current_defence, current_health;
    int health,attack,defence;
    int base_health,base_attack,base_defence;

    int sheild,sword,potion = 20;
    int sheild_no = 0; 
    int sword_no = 0;
    int potion_no = 0;





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

    


   

    
    
    int age;
    int Class;
    
    string gender;
    string Create_choice;
    int race;

  
    char confirmation;
     int m,M,f,F;
};

#endif
