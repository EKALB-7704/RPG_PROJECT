#include "Store.h"
#include "player.h"
#include <iostream>
#include <string>

// Implementations of store class member functions.
// The interactive loop and input handling should be placed in main() or another controller file.
int choice;
void store::town(Player &player)
{ 
display_gold(player.gold);
store_menu();
std::cin >> choice;
if (choice == 1)
{    buy_potion(player.gold, player.potion_no);
}
else if (choice == 2)
{
    buy_sword(player.gold, player.attack);
}
else if (choice == 3)
{
    buy_shield(player.gold, player.defence);
}
else
{   
    std::cout << "Invalid choice, please try again.\n";
}
}  

void store::store_menu()
{
std::cout << "==========================================================================================================\n";
std::cout << "          <Shop> Welcome to the store! What would you like to buy? \n";
std::cout << " (1) Potion                                 " << potion_price << " gold                               Heals 20HP\n";
std::cout << " (2) Shield Upgrade                         " << shield_price << " gold                                +20 DEF\n";
std::cout << " (3) Sword Upgrade                          " << sword_price << " gold                                +20 ATK\n";
std::cout << "==========================================================================================================\n";

std::cout << "==========================================================================================================\n";
               
std::cout << "==========================================================================================================\n";

    std::cout << "Welcome to the store! What would you like to buy? \n";
 
}

void store::display_gold(int &gold)
{
      std::cout << "You have " << gold << " gold\n";
}
void store::buy_potion(int &gold, int &potions)
{
    if (gold >= potion_price)
    {
        gold -= potion_price;
        potions ++; // Increase potion by 1
        std::cout << "You bought a potion!.\n";
    }
    else
    {
        std::cout << "Not enough gold to buy a potion so get out of my store.\n";
    }
}

void store::buy_sword(int &gold, int &current_strength)
{
    if (gold >= sword_price)
    {
        gold -= sword_price;
        current_strength += 10; // Increase strength by 10
        std::cout << "You bought a sword! Strength increased by 10.\n";
    }
    else
    {
        std::cout << "Not enough gold to buy a sword; could I interest you in a potion or shield instead?\n";
    }
}

void store::buy_shield(int &gold, int &current_defense)
{
    if (gold >= shield_price)
    {
        gold -= shield_price;
        current_defense += 15; // Increase defense by 15
        std::cout << "You bought a shield! Defense increased by 15.\n";
    }
    else
    {
        std::cout << "Not enough gold to buy a shield; maybe a potion would suit you better.\n";
    }
}

void store::dialogue_cycle()
{
    
}

