#pragma once

#include "Player.h"
#include <iostream>

enum class BattleResult { Victory, Defeat, BossDefeated };

BattleResult battle(Player &player);
