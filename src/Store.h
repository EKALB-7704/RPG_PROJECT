#pragma once 

#include "Player.h"

#include <string>



class store
{
    private:
    int potion_price = 10;
    int sword_price = 50;
    int shield_price = 40;

   


    public:
    void store_menu();
    void town(Player &player);
    void buy_potion(int &gold, int &potions);
    void buy_sword(int &gold, int &current_strength);
    void buy_shield(int &gold, int &current_defense);
    void display_gold(int gold) const;
    

     

    
   };