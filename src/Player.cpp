#include "Player.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

void Player::heal() {
    if (potion > 0) {
        int before = current_health;
        current_health = std::min(current_health + 12, maxHP);
        potion--;
        std::cout << "You healed " << current_health - before << " HP.\n";
    } else {
        std::cout << "No potions left!\n";
    }
}

int Player::specialAttack() {
    if (stamina > 0)
    {
    int dmg = current_attack + (rand() % 6 + 4);
    std::cout << "You unleash a POWER STRIKE for " << dmg << " damage!\n";
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
    std::cout << "You gained " << amount << " EXP.\n";

    while (exp >= level * 20)
    {
        exp -= level * 20;
        level++;

        current_attack += 2;
        current_defence += 2;
        maxHP = base_health + 10 * (level - 1);
        current_health = maxHP;
        maxStamina = level;
        stamina = maxStamina;
        std::cout << "LEVEL UP! You are now level " << level << "!\n";
    }
}
