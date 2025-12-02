
#include "player.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Player::Player(string n) {
    name = n;
    maxHP = 30;
    hp = maxHP;
    attack = 8;
    level = 1;
    level_reference = level-1;
    exp = 0;
    potion = 3;
    maxStamina = level;
    stamina = maxStamina;
    gold = 0;
}

void Player::heal() {
    if (potion > 0) {
        hp += 12;
        if (hp > maxHP) hp = maxHP;
        potion--;
        cout << "You healed 12 HP.\n";
    } else {
        cout << "No potions left!\n";
    }
}

int Player::specialAttack() {
    if (stamina > 0)
    {
    int dmg = attack + (rand() % 6 + 4);
    cout << "You unleash a POWER STRIKE for " << dmg << " damage!\n";
    stamina--;
    return dmg;
    }
    else 
    {
        std::cout << "you are out of stamina!\n ";
        int dmg = 0;
        return dmg;
    }
}

void Player::gainExp(int amount) {
    exp += amount;
    cout << "You gained " << amount << " EXP.\n";

    if (exp >= level * 20) 
    {
        level++;
        exp = 0;
        maxHP += 10;
        attack += 2;
        hp = maxHP;
        maxStamina = level;
        stamina = maxStamina;
        cout << "LEVEL UP! You are now level " << level << "!\n";
    }
}
