#include "Player.h"
#include "Store.h"
#include "Input.h"
#include <iostream>
#include <string>



void Player::Name()
{
    std::cout << "========================================================================================================================" << std::endl;
    std::cout << std::string(40, ' ') << "Welcome to the Character Creation Screen" << std::endl;
    std::cout << "========================================================================================================================" << std::endl; 
    do {
        name = readLine("What is your name? ");
    } while (name.find_first_not_of(" \t") == std::string::npos);  // reject empty / whitespace-only
}

void Player::Age()
{
    do {
        age = readInt("How old is your character? (5-100): ", 5, 100);
    } while (!readYesNo("Your age is " + std::to_string(age) + ". Is that correct?"));
}

void Player::Gender()
{
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << std::string(46, ' ') << "Character Gender Selection" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    do {
        gender = readLine("What gender is your character? ");
    } while (!readYesNo("Your gender is " + gender + ". Is that correct?" ));
}


void Player::Race()
{
    
        
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::string(42, ' ') << "Now Select Your Character's Race" << std::endl;
    std::cout << std::string(32, ' ') << "Your character's race determines your starting location" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl; 
   std::cout << std::string(40, ' ') << "(1)|Goblin| Swamp    (3)|Dwarf| Mountains" << std::endl;
   std::cout << std::string(40, ' ') << "(2)| Elf  | Forest   (4)|Human| Plains" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    
    do {
        race = readInt("What race is your character? ", 1, 4);
        if (race == 1) p_race = "Goblin";
        if (race == 2) p_race = "Elf";
        if (race == 3) p_race = "Dwarf";
        if (race == 4) p_race = "Human";
    }
    while (!readYesNo("Your race is " + p_race + ". Is that correct?"));

    
}

void Player::Class_()
{
    
        
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::string(46, ' ') << "Now Select Your Character's Class" << std::endl;
    std::cout << std::string(36, ' ') << "Your characters Class determines your starting stats" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl; 
   
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl; 
    std::cout << std::string(36, ' ') << "|=============||========||=======||=======||" << std::endl;
    std::cout << std::string(36, ' ') << "|             || Health ||  ATK  ||  DEF  ||" << std::endl;
    std::cout << std::string(36, ' ') << "|=============||========||=======||=======||" << std::endl;
    std::cout << std::string(36, ' ') << "|             ||        ||       ||       ||" << std::endl;
    std::cout << std::string(36, ' ') << "| Warrior(1)  ||   40   ||   7   ||  15   ||" << std::endl;
    std::cout << std::string(36, ' ') << "|             ||        ||       ||       ||" << std::endl;
    std::cout << std::string(36, ' ') << "|=============||========||=======||=======||" << std::endl;
    std::cout << std::string(36, ' ') << "|             ||        ||       ||       ||" << std::endl;
    std::cout << std::string(36, ' ') << "| Mage   (2)  ||   30   ||  12   ||   8   ||" << std::endl;
    std::cout << std::string(36, ' ') << "|             ||        ||       ||       ||" << std::endl;
    std::cout << std::string(36, ' ') << "|=============||========||=======||=======||" << std::endl;
    std::cout << std::string(36, ' ') << "|             ||        ||       ||       ||" << std::endl;
    std::cout << std::string(36, ' ') << "| Archer (3)  ||   25   ||  10   ||  12   ||" << std::endl;
    std::cout << std::string(36, ' ') << "|             ||        ||       ||       ||" << std::endl;
    std::cout << std::string(36, ' ') << "|=============||========||=======||=======||" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

    
        
     do {
        Class = readInt("Select your class: ", 1, 3);
        if (Class == 1) p_class = "Warrior";
        if (Class == 2) p_class = "Mage";
        if (Class == 3) p_class = "Archer";
    } while (!readYesNo("You have chosen " + p_class + ". Is that correct?"));
}

void Player::quest()
{
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::string(35, ' ') << "Finally will you accept the quest to defeat the skeleton king " << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::string(40, ' ') << " (1)|Defeat Skeleton King| (2)|No Quest|           " << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    int quest_choice = readInt("Do you accept?: ", 1, 2);
    if (quest_choice == 1) std::cout << "Beware the skeleton king." << std::endl;
    if (quest_choice == 2) std::cout << "I wish you luck." << std::endl;
}

void Player::Create()
{
    Name();
    Age();
    Gender();
    Race();
    Class_();
    quest();
    starting_stats();
}

void Player::Character_Readback()
{
    
    std::cout << "you are a " << age << " year old " << p_race <<" "<< p_class << " named " << name << std::endl; 
}
//This is as far as I got for the character creator

void Player::starting_stats()
{
    // assume member 'Class' is an int where 1=warrior, 2=mage, 3=archer
    if (Class == 1) // warrior
    {
        p_class = "Warrior";
        base_attack =7;
        base_defence = 15;
        base_health = 40;
        maxHP = 40;
    }
    else if (Class == 2) // mage
    {
        p_class = "Mage";
        base_attack = 12;
        base_defence = 8;
        base_health = 30;
        maxHP = 30;
    }
    else if (Class == 3) // archer
    {
        p_class = "Archer";
        base_attack = 10;
        base_defence = 12;
        base_health = 25;
        maxHP = 25;
    }

    // compute current stats once
    current_attack = base_attack;
    current_defence = base_defence;
    current_health = base_health;

    // race determines starting location
    switch (race)
    {
        case 1: location = "SWAMP"; break;      // Goblin
        case 2: location = "FOREST"; break;     // Elf
        case 3: location = "MOUNTAINS"; break;  // Dwarf
        case 4: location = "PLAINS"; break;     // Human
    }
    std::cout << "You begin your journey in the " << location << ".\n";

}
void Player::stats_readback()
{
  

        std::cout << " Strength: " << current_attack << std::endl;
        std::cout << " Defence: " << current_defence << std::endl;
        std::cout << " Health: " << current_health << std::endl;
        std::cout << " Level: " << level << std::endl;
        std::cout << " Gold: " << gold << std::endl;


}


