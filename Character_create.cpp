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
    std::cout << "you are a " << Age << " year old " << Gender << " " << Race << " named " << Name << endl; 
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



