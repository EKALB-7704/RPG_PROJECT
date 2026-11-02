#include "Battle.h"
#include "Input.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>

BattleResult battle(Player &player) {

  // Pull a random monster from the pool to fight and display it
  Monster new_enemy = returnOpponent(player.level);
  new_enemy.Display_Monster(player.location);

  std::cout << "\n A wild " << new_enemy.name << " appears!\n";

  // Keep the combat loop running while both the player and the
  // monster are alive (health > 0)
  while (player.current_health > 0 && new_enemy.hp > 0) {

    // Display monster and player current stats (health, stamina etc.)
    std::cout << "\nYour HP: " << player.current_health << "/" << player.maxHP
              << "\n"
              << "Your Stamina: " << player.stamina << "/" << player.maxStamina
              << "\n";
    std::cout << new_enemy.name << " HP: " << new_enemy.hp << "\n";
    std::cout << "Potions: " << player.potion << "\n";

    // Display action options and take in user input
    std::cout << "\nChoose action:\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Heal\n";
    std::cout << "3. Special Attack\n";

    int choice = readInt("> ", 1, 3);

    if (choice == 1) // 1 = attack
    {
      // Do calc for damage dealt to monster
      int dmg = rand() % player.current_attack + 1;
      new_enemy.Display_Monster(player.location);
      std::cout << "You deal " << dmg << " damage.\n";
      new_enemy.hp -= dmg;
    } else if (choice == 2) // 2 = consume potion to heal
    {
      // Run heal function
      new_enemy.Display_Monster(player.location);
      player.heal();
    } else if (choice == 3) // 3 = special attack
    {
      // Run special attack function
      new_enemy.Display_Monster(player.location);
      int dmg = player.specialAttack();
      new_enemy.hp -= dmg;
    }

    // Monster damage dealt to player calc
    if (new_enemy.hp > 0) {
      int dmg = rand() % new_enemy.attack + 1;
      std::cout << new_enemy.name << " hits you for " << dmg << "!\n";
      int true_dmg = (dmg - (player.current_defence / 6));
      if (true_dmg < 0) {
        true_dmg = 0;
      }
      player.current_health -= true_dmg;
    }
  }

  // Condition check to see if the player is dead
  if (player.current_health <= 0) {
    std::cout << "\n You were defeated...\n";
    return BattleResult::Defeat;
  }

  // Victory message and reward calc for defeating a monster
  std::cout << "\n You defeated the " << new_enemy.name << "!\n";
  player.gainExp(new_enemy.rewardExp);
  player.gold += new_enemy.rewardGold;
  player.kill_count++;
  std::cout << "You found " << new_enemy.rewardGold << " gold!\n";

  return new_enemy.getIsBoss() ? BattleResult::BossDefeated
                               : BattleResult::Victory;
}
