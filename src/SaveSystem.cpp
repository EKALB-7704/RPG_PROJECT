#include "SaveSystem.h"
#include <fstream>
#include <iostream>
#include <string>

namespace {
const char *const kSavePath = "save.txt";
const std::string kSaveHeader = "SKELETON_QUEST_SAVE 1";  // bump the number if the format changes
}

bool saveGame(const Player &player)
{
    std::ofstream file(kSavePath, std::ios::trunc);
    if (!file) {
        std::cout << "Could not open " << kSavePath << " for writing.\n";
        return false;
    }

    file << kSaveHeader << '\n'
         << player.name << '\n'  // own line so names with spaces survive
         << player.p_class << ' ' << player.p_race << ' ' << player.location << '\n'
         << player.level << ' ' << player.exp << ' ' << player.gold << ' '
         << player.potion << ' ' << player.kill_count << '\n'
         << player.current_health << ' ' << player.maxHP << ' '
         << player.stamina << ' ' << player.maxStamina << '\n'
         << player.base_health << ' ' << player.base_attack << ' ' << player.base_defence << '\n'
         << player.current_attack << ' ' << player.current_defence << '\n'
         << player.area_cleared << '\n';

    return static_cast<bool>(file);
}

bool loadGame(Player &player)
{
    std::ifstream file(kSavePath);
    if (!file) {
        std::cout << "No save file found.\n";
        return false;
    }

    std::string header;
    if (!std::getline(file, header) || header != kSaveHeader) {
        std::cout << "Save file is from an older version or is corrupt.\n";
        return false;
    }

    // Load into a copy so a half-read file never leaves the real player in a broken state.
    Player loaded = player;
    std::getline(file, loaded.name);
    file >> loaded.p_class >> loaded.p_race >> loaded.location
         >> loaded.level >> loaded.exp >> loaded.gold >> loaded.potion >> loaded.kill_count
         >> loaded.current_health >> loaded.maxHP >> loaded.stamina >> loaded.maxStamina
         >> loaded.base_health >> loaded.base_attack >> loaded.base_defence
         >> loaded.current_attack >> loaded.current_defence
         >> loaded.area_cleared;

    if (!file) {
        std::cout << "Save file is incomplete or corrupt.\n";
        return false;
    }

    player = loaded;
    return true;
}
