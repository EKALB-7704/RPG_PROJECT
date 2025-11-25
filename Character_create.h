#pragma once 

#include <string>


using namespace std;



class Character
{
    private:
    int Class; // 1=warrior, 2=mage, 3=archer
    int level= 0;
    int base_health= 100;
    int base_strength = 10;
    int base_defense = 10;
    int gold = 0;


    void age_years();
    void gender();
    void race();
    void name();
    

    
    




    public:
    void starting_stats();
    void create_prompt();
    void create();
    void character_readback();
    int Age;
    string Name;
    string Gender;
    string Race;
    string Create_choice;
    int current_strength;
    int current_defense;
    int current_health;
    int current_gold;

};
    
    



