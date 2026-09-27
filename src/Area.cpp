#include "Area.h"
#include "Input.h"
#include <array>
#include <iostream>
#include <string>

//Function for displaying current location, useful if you get lost.
void Area::current_area(const Player &player) const
{
    std::cout << "You are currently in [" << player.location << "]\n";
}

//Function for travelling from area to area
void Area::travel(Player &player)
{
    static const std::array<std::string, 4> areas{"FOREST", "PLAINS", "MOUNTAINS", "SWAMP"};

    std::cout << "Where would you like to go?\n";
    for (std::size_t i = 0; i < areas.size(); ++i)
        std::cout << i + 1 << ". " << areas[i] << '\n';

    const std::string &destination = areas[readInt("> ", 1, 4) - 1];
    if (destination == player.location)
    {
        std::cout << "You are already in the " << destination << ".\n";
        return;
    }

    player.location = destination;
    player.area_cleared = false;
    std::cout << "You have traveled to the " << destination << ".\n";
}
