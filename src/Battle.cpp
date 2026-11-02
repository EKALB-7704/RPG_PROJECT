#include "Battle.h"
#include "Monster.h"
#include <iostream>

BattleResult battle(Player &player) {

  // Pull a random monster from the pool to fight
  Monster new_enemy = returnOpponent(player.level);
  new_enemy.Display_Monster(player.location);

  std::cout << "\nA wild " << new_enemy.name << " appears! \n";

  while ((player.current_health > 0 && new_enemy.hp > 0)) {

    std::cout << "\nYour HP" << player.current_health << "/"
  }
}
