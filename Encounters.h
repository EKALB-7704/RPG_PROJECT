#pragma once 
#include <string>
#include <vector>

using namespace std;

class Encounters

{
    private:


    public:
    void enemy_create();
    void enemy_stats();
    string Enemy;
    string Enemies[6] = {"ORC", "TROLL", "WOLF", "WITCH", "SKELETON", "GOBLIN"}; //placeholder enemies


};