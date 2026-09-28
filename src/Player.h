#pragma once

#include <string>

class Player
{
    // Character creation steps, run in order by Create()
    private:
    void Age();
    void Gender();
    void Race();
    void Name();
    void Class_();
    void quest();

    public:
    // Identity
    std::string name;
    std::string gender;
    std::string p_race;
    std::string p_class;
    int age = 0;
    int race = 0;   // 1=Goblin, 2=Elf, 3=Dwarf, 4=Human
    int Class = 0;  // 1=Warrior, 2=Mage, 3=Archer

    // World
    std::string location;
    bool area_cleared = false;  // true once this area's enemy is beaten; reset by travelling

    // Progress
    int level = 1;
    int exp = 0;
    int gold = 0;
    int potion = 3;
    int kill_count = 0;

    // Stats (base_* are set by class; current_* include level-ups and shop upgrades)
    int base_health = 0, base_attack = 0, base_defence = 0;
    int current_health = 0, maxHP = 0;
    int current_attack = 0, current_defence = 0;
    int stamina = 1, maxStamina = 1;

    void Create();
    void starting_stats();
    void Character_Readback();
    void stats_readback();

    void heal();
    int specialAttack();
    void gainExp(int amount);
};
