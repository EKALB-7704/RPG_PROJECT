#include "Store.h"
#include "Input.h"
#include <iostream>
#include <string>

void store::town(Player &player)
{
    display_gold(player.gold);
    store_menu();

    switch (readInt("> ", 1, 4))
    {
        case 1: buy_potion(player.gold, player.potion); break;
        case 2: buy_shield(player.gold, player.current_defence); break;
        case 3: buy_sword(player.gold, player.current_attack); break;
        case 4: std::cout << "Thank you for visiting the store! Come again!\n"; break;
    }
}

void store::store_menu()
{
    std::cout << "==========================================================================================================\n";
    std::cout << "          <Shop> Welcome to the store! What would you like to buy? \n";
    std::cout << " (1) Potion                                 " << potion_price << " gold                              Heals 12HP\n";
    std::cout << " (2) Defense Upgrade                         " << shield_price << " gold                               +5 DEF\n";
    std::cout << " (3) Attack Upgrade                          " << sword_price << " gold                                +5 ATK\n";
    std::cout << " (4) Exit Store\n";
    std::cout << "==========================================================================================================\n";
}

void store::display_gold(int gold) const
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
        std::cout << "Not enough gold to buy a potion.\n";
    }
}

void store::buy_sword(int &gold, int &current_strength)
{
    if (gold >= sword_price)
    {
        gold -= sword_price;
        current_strength += 5; // Increase strength by 5
        std::cout << "You bought a sword! attack increased by 5.\n";
    }
    else
    {
        std::cout << "Not enough gold to buy a sword.\n";
    }
}

void store::buy_shield(int &gold, int &current_defense)
{
    if (gold >= shield_price)
    {
        gold -= shield_price;
        current_defense += 5; // Increase defense by 5
        std::cout << "You bought a shield! Defense increased by 5.\n";
    }
    else
    {
        std::cout << "Not enough gold to buy a shield.\n";
    }
}

