#include "Character_create.h"
#include <iostream>
#include <string>


void Character::name()
{
    std::cout << "what is your name? ";
    std::cin >> Name;
}

void Character::age_years()
{
    std::cout << "what is your age? ";
    std::cin >> Age;
}

void Character::gender()
{
    std::cout << "what is your gender? ";
    std::cin >> Gender;
}

void Character::race()
{
    std::cout << "what race are you? ";
    std::cin >> Race;
}

void Character::create()
{
    name();
    age_years();
    gender();
    race();
}

void Character::character_readback()
{
    std::cout << "Character Created! \n";
    std::cout << "you are a " << Age << " year old " << Gender << " " << Race << " named " << Name << std::endl; 
}

void Character::create_prompt()
{
    std::cout << "would you like to create a character, [Y/N] ";
    std::cin >> Create_choice;
    if (Create_choice == "Y")
    {
        create();
    }
}

void Character::starting_stats()
{
    // assume member 'Class' is an int where 1=warrior, 2=mage, 3=archer
    if (Class == 1) // warrior
    {
        base_strength += 0;
        base_defense += 5;
        base_health += 20;
    }
    else if (Class == 2) // mage
    {
        base_strength += 5;
        base_defense -= 5;
        base_health += 0;
    }
    else if (Class == 3) // archer
    {
        base_strength += 0;
        base_defense += 0;
        base_health += 25;
    }

    // compute current stats once
    current_strength = base_strength + (level * 1);
    current_defense = base_defense + (level * 1);
    current_health = base_health + (level * 5);

}
void Character::stats_readback()
{
  

        std::cout << " Strength: " << current_strength << std::endl;
        std::cout << " Defense: " << current_defense << std::endl;
        std::cout << " Health: " << current_health << std::endl;
        std::cout << " Level: " << level << std::endl;
        std::cout << " Gold: " << current_gold << std::endl;

}

