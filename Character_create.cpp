//Framework for character creator, function definitions will be replaced by 
//charlies code once fully implemented


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

void Character::C_Class()
{
    std::cout << "what class are you " << endl;
    std::cout << "[ARCHER] [KNIGHT] [MAGE]";
    std::cin >> c_class;

    if (c_class == "ARCHER")
    {
        HEALTH = 20;
        ATTACK = 3;
        DEFENSE = 2;
        PLAYER_LEVEL = 1;
    }
    else if (c_class == "KNIGHT")
    {
        HEALTH = 20;
        ATTACK = 2;
        DEFENSE = 5;
        PLAYER_LEVEL = 1;
    }
    else if (c_class == "MAGE")
    {
        HEALTH = 20;
        ATTACK = 5;
        DEFENSE = 2;
        PLAYER_LEVEL = 1;
    }

}

void Character::stats_readback()
{
    std::cout << "HEALTH:" << HEALTH << endl << "ATTACK:" << ATTACK << endl << "DEFENSE:" << DEFENSE << endl;
}

void Character::create()
{

    name();
    age_years();
    gender();
    race();
    C_Class();
    //character_exists = true;
}

void Character::character_readback()
{
    std::cout << "Character Created! \n";
    std::cout << "you are a " << Age << " year old " << Gender << " " << Race <<" "<< c_class << " named " << Name << endl; 
}

void Character::create_prompt()
{
        std::cout << "would you like to create a character?, [Y/N] ";
        std::cin >> Create_choice;
        if (Create_choice == "Y")
        {
        create();
        character_readback();
        }
}



