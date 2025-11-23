#include "Area.h"
#include "Encounters.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>




  


void Encounters::enemy_create()
{
   std::srand ( time(NULL) ); //initialize the random seed
  

  
  int RandIndex = rand() % 6; //generates a random number between 0 and 6
  std::cout << "A "<< Enemies[RandIndex] << " has appeared!" << endl;

}
void Encounters::enemy_stats()
{
  
}