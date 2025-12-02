#pragma once 
#include <string>
#include <vector>
#include "player.h"


using namespace std;
Player player;
class Encounters

{
    private:
    int enemy_health;
    int enemy_attack;
    int enemy_damage=(enemy_attack-player.current_defense);
    int LEVEL_REFERENCE = 1 ;
    


    public:
    void random_encounter();
    void enemy_create();
    void enemy_stats();
    string current_enc;
    string Enemy;
    string Encounters[4] = {"COMBAT", "MERCHANT", "TREASURE", "TRAP"};
    string Enemies[7] = {"ORC", "TROLL", "WOLF", "WITCH", "SKELETON", "GOBLIN", "BANDIT"}; //placeholder enemies


};