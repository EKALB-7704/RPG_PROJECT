#pragma once

#include "Player.h"
#include "Rng.h"

enum class BattleResult { Victory, Defeat, BossDefeated };

BattleResult battle(Player &player, Rng &rng);
