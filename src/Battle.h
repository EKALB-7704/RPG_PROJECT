#pragma once

#include "Player.h"

enum class BattleResult { Victory, Defeat, BossDefeated };

BattleResult battle(Player &player);
