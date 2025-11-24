#include "Area.h"
#include "Encounters.h"
#include "Character_create.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>





void Encounters::random_encounter()
{
  std::srand (time(NULL));
  int RandEnc = (rand() % 4) + 1; // generates a random number between 0 and 4
  
  switch (RandEnc)
  {

  

  case 1:
    current_enc = "COMBAT";
    enemy_create();
    break;
    
  case 2: 
    current_enc = "MERCHANT";
    //callums merchant function will go here, after it has been defined and implemented
    std::cout << "You have met a merchant!" << endl;
    break;

  case 3:
    current_enc = "TREASURE";
    //random loot like treasure chest, sword in the stone etc.
    std::cout << "you found some treasure!" << endl;
    break;

  case 4:
    current_enc = "TRAP";
    //poison darts, bear trap etc.
    std::cout << "you fell into a trap!" << endl;
    break;

  

  

  }
}
  


void Encounters::enemy_create()
{
   std::srand ( time(NULL) ); //initialize the random seed
  

  
  int RandIndex = rand() % 6; //generates a random number between 0 and 6
  std::cout << "A "<< Enemies[RandIndex] << " has appeared!" << endl;

}
void Encounters::enemy_stats()
{
  enemy_health = 10 * LEVEL_REFERENCE;

  
}