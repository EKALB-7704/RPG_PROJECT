#ifndef SAVE_SYSTEM_H
#define SAVE_SYSTEM_H

#include <fstream>
#include <iostream>
#include "Player.h"
using namespace std;

bool saveGame(const Player &player) 
{
    ofstream file("./save.txt", ios::trunc);  // Force local working directory

    if (!file.is_open()) {
        cout << "DEBUG: Could not open save.txt for writing.\n";
        return false;
    }

    file << player.name << "\n";
    file << player.hp << "\n";
    file << player.maxHP << "\n";
    file << player.stamina << "\n";
    file << player.maxStamina << "\n";
    file << player.attack << "\n";
    file << player.level << "\n";
    file << player.exp << "\n";
    file << player.potions << "\n";
    file << player.gold << "\n";

    file.close();
    return true;
}

bool loadGame(Player &player) 
{
    ifstream file("./save.txt");

    if (!file.is_open()) {
        cout << "DEBUG: Could not open save.txt for reading.\n";
        return false;
    }

    file >> player.name;
    file >> player.hp;
    file >> player.maxHP;
    file >> player.stamina;
    file >> player.maxStamina;
    file >> player.attack;
    file >> player.level;
    file >> player.exp;
    file >> player.potions;
    file >> player.gold;

    file.close();
    return true;
}

#endif

