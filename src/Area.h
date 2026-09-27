#pragma once

#include "Player.h"

class Area
{
public:
    void travel(Player &player);
    void current_area(const Player &player) const;
};
