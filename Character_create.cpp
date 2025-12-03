#include "player.h"
#include "Store.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;
using std::string;



void Player::Name()
{
    cout << "========================================================================================================================" << endl;
    cout << string(40, ' ') << "Welcome to the Character Creation Screen" << endl;
    cout << "========================================================================================================================" << endl; 
    cout << "what is your name? ";
    cin >> name;
}

void Player::Age()
{
    bool character_confirmed = false;

    cout<<"------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<string(45, ' ')<<"Next choose your characters age " << endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<string(48, ' ')<<"(Min Age is 5 )" << endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------" << endl;

    while (character_confirmed == false) {
        cout << "How old is your character?: ";
        cin >> age;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    
    cout << "Your age is " << age << endl; 
    if (age < 5) {
            cout << string(40, ' ') << "|Min Age is 5| " << endl;
            cout << "Please try again." << endl;
            continue;

    } else if (age > 100) {
            cout <<string(40, ' ')<< "|Max Age is 100|" << endl;
            cout << "Please try again." << endl;
            continue;

    } else {
    cout << "Is that correct? (Y/N)" << endl;        
    }

    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {
        cout << "Continue!" << endl;
         character_confirmed = true;
    } else {
        cout << "Please try again." << endl;
        continue;
    }  
    }
}

void Player::Gender()
{
    M = m = 0;
    F = f = 1;
    bool character_confirmed = false;
    
    while (character_confirmed == false) {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << string(46, ' ') << "Character Gender Selection" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "First select your character's gender." << endl;
        cout << "Are you Male or Female? (M/F): ";
        cin >> gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


if (gender[0] != 'M' && gender[0] != 'F' && gender[0] != 'm' && gender[0] != 'f')
        {
            cout << "Invalid input." << endl;
    
        }
          else {
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl; 
            cout << string(33, ' ') << "Note only your first input will be read, ex (Mf = Male)" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "You have selected "<<gender<< "." << endl;
            cout << "Is that correct? (Y/N)" << endl;

            cin >> confirmation;
            

            if (confirmation == 'Y' || confirmation == 'y') {
                cout << "Continue!" << endl;
                character_confirmed = true;
            } else {
                cout << "Please try again." << endl;
                continue;
            }
        }
    }
}

void Player::Race()
{
    bool character_confirmed = false;
        
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << string(42, ' ') << "Now Select Your Character's Race" << endl;
    cout << string(32, ' ') << "Your characters race determins your starting location" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl; 
   cout << string(40, ' ') << "(1)|Goblin| Swamp    (3)|Dwarf| Mountains" << endl;
   cout << string(40, ' ') << "(2)| Elf  | Forest   (4)|Human| Village" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    

    while (character_confirmed == false) {
        cout << "Select your race?: ";
        cin >> race;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else if (race < 1 || race > 4) {
            cout << "Invalid input." << endl; 
            continue;
        } else {
            
            if (race == 1) {
                cout << "You have chosen Goblin. " << endl;
            } else if (race == 2) { 
                cout << "You have chosen Elf. " << endl;
            } else if (race == 3) { 
                cout << "You have chosen Dwarf. " << endl; 
            } else if (race == 4) { 
                cout << "You have chosen Human. " << endl;
            }

            cout << "Is that correct? (Y/N)" << endl;        
            cin >> confirmation;

            if (confirmation == 'Y' || confirmation == 'y') {
                cout << "Continue!" << endl;
                character_confirmed = true;
            } else {
                cout << "Please try again." << endl;
                continue;
            }
        }
    }
}

void Player::Class_()
{
    bool character_confirmed = false;
        
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << string(46, ' ') << "Now Select Your Character's Class" << endl;
    cout << string(36, ' ') << "Your characters Class determines your starting stats" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl; 
   
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << string(36, ' ') << "|=============||========||=======||=======||" << endl;
    cout << string(36, ' ') << "|             || Health ||  ATK  ||  DEF  ||" << endl;
    cout << string(36, ' ') << "|=============||========||=======||=======||" << endl;
    cout << string(36, ' ') << "|             ||        ||       ||       ||" << endl;
    cout << string(36, ' ') << "| Warrior(1)  ||   40   ||  10   ||  15   ||" << endl;
    cout << string(36, ' ') << "|             ||        ||       ||       ||" << endl;
    cout << string(36, ' ') << "|=============||========||=======||=======||" << endl;
    cout << string(36, ' ') << "|             ||        ||       ||       ||" << endl;
    cout << string(36, ' ') << "| Mage   (2)  ||   30   ||  20   ||  10   ||" << endl;
    cout << string(36, ' ') << "|             ||        ||       ||       ||" << endl;
    cout << string(36, ' ') << "|=============||========||=======||=======||" << endl;
    cout << string(36, ' ') << "|             ||        ||       ||       ||" << endl;
    cout << string(36, ' ') << "| Archer (3)  ||   35   ||  15   ||  10   ||" << endl;
    cout << string(36, ' ') << "|             ||        ||       ||       ||" << endl;
    cout << string(36, ' ') << "|=============||========||=======||=======||" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    while (character_confirmed == false) {
        cout << "Select your class?: ";
        cin >> Class;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else if (Class < 1 || Class > 3) {
            cout << "Invalid input." << endl; 
            continue;
        } else {
            
            if (Class == 1) {
                cout << "You have chosen Warrior. " << endl;
            } else if (Class == 2) { 
                cout << "You have chosen Mage. " << endl; 
            } else if (Class == 3) { 
                cout << "You have chosen Archer. " << endl;
            }

            cout << "Is that correct? (Y/N)" << endl;        
            cin >> confirmation;

            if (confirmation == 'Y' || confirmation == 'y') {
                cout << "Continue!" << endl;
                character_confirmed = true;
            } else {
                cout << "Please try again." << endl;
                continue;
            }
        }
    } 
}
void Player::quest()
{
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << string(35, ' ') << "Finally will you accept the quest to defeat the skeleton king " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << string(40, ' ') << " (1)|Defeat Skeleton King| (2)|No Quest|           " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Select your starting quest?: ";
    int quest_choice;
    cin >> quest_choice;
    switch (quest_choice) {
        case 1: quest_choice = 1;
            cout << "Beware the skeleton king." << endl;
            break;
        case 2: quest_choice = 2;
            cout << "I wish you luck." << endl;
            break;
        default:
            cout << "Invalid choice. No quest selected." << endl;
            break;
    }
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
    std::cout << "Character Created! \n";
    std::cout << "you are a " << age << " year old " << gender << " " << race << " named " << name << endl; 
}
//This is as far as I got for the character creator

void Player::starting_stats()
{
    // assume member 'Class' is an int where 1=warrior, 2=mage, 3=archer
    if (Class == 1) // warrior
    {
        base_attack =7;
        base_defence = 15;
        base_health = 40;
        maxHP = 40;
    }
    else if (Class == 2) // mage
    {
        base_attack = 12;
        base_defence = 8;
        base_health = 30;
        maxHP = 30;
    }
    else if (Class == 3) // archer
    {
        base_attack = 10;
        base_defence = 12;
        base_health = 25;
        maxHP = 25;
    }

    // compute current stats once
    current_attack = base_attack;
    current_defence = base_defence;
    current_health = base_health;

}
void Player::stats_readback()
{
  

        std::cout << " Strength: " << current_attack << std::endl;
        std::cout << " Defence: " << current_defence << std::endl;
        std::cout << " Health: " << current_health << std::endl;
        std::cout << " Level: " << level << std::endl;
        std::cout << " Gold: " << gold << std::endl;

}

void Player::create_prompt()

{
    std::cout << "Would you like to create a character?  [Y/N]\n";
    std::cin >> Create_choice;
    if (Create_choice == "Y")
    {
    Create();
    }
    
        
    
}
