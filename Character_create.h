#pragma once 

#include <string>


using namespace std;



class Character
{
    private:



    void age_years();
    void gender();
    void race();
    void name();
    void C_Class();
    

    
    




    public:
    void create_prompt();
    void create();
    void character_readback();
    void stats_readback();
    int Age;
    int ATTACK, DEFENSE, HEALTH, PLAYER_LEVEL;
    
    string Name;
    string Gender;
    string Race;
    string c_class;
    string Create_choice;
   
    
    


};
