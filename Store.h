#pragma once 

#include "player.h"

#include <string>


using namespace std;

class store
{
    private:
    int choice;
    int potion_price = 10;
    int sword_price = 50;
    int shield_price = 40;

   


    public:
    void store_menu();
    void town(Player &player);
    void buy_potion(int &gold, int &current_health);
    void buy_sword(int &gold, int &current_strength);
    void buy_shield(int &gold, int &current_defense);
    void dialogue_cycle();
     void display_gold(int &gold);
    

     

    
   };