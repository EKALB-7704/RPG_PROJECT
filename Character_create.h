#pragma once 
#include <string>
using namespace std;


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

    string Create_choice;  
    char confirmation;
     int m,M,f,F;
    
     Character(int age, string name, string gender, int race, int Class)
     {
        this->age = age;
        this->name = name;
        this->gender = gender;
        this->race = race;
        this->Class = Class;
        }

        //Stats
        int current_health;
        int current_strength;
        int current_defense;
        int current_gold;
        
        int base_health;
        int base_strength;
        int base_defense;
        int level;
        int gold = 0;
    

};



