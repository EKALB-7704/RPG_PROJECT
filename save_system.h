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
    file << player.current_health << "\n";
    file << player.maxHP << "\n";
    file << player.stamina << "\n";
    file << player.maxStamina << "\n";
    file << player.current_attack << "\n";
    file << player.current_defence << "\n";
    file << player.level << "\n";
    file << player.exp << "\n";
    file << player.potion << "\n";
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
    file >> player.current_health;
    file >> player.maxHP;
    file >> player.stamina;
    file >> player.maxStamina;
    file >> player.current_attack;
    file >> player.current_defence;
    file >> player.level;
    file >> player.exp;
    file >> player.potion;
    file >> player.gold;

    file.close();
    return true;
}

#endif

