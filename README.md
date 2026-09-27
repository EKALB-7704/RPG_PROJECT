# Skeleton Quest

A text-based RPG for the terminal, written in C++17. Create a character, travel between areas, fight skeletons, level up, buy upgrades, and defeat the Skeleton King.

## Features

- **Character creation:** choose from 4 races (each sets your starting area) and 3 classes with different starting stats
- **Turn-based combat:** attack, heal with potions, or use a stamina-limited special attack
- **Levelling:** XP carries over between levels; each level raises HP, ATK, DEF and stamina
- **World map:** travel between the Forest, Plains, Mountains and Swamp
- **Shop:** spend gold on potions and attack/defence upgrades
- **Save/load:** versioned save file, with corrupt or outdated saves rejected safely
- **Boss fight:** the Skeleton King appears at level 5, and beating him wins the game

## Building and running

Requires CMake 3.16+ and a C++17 compiler (GCC, Clang or MSVC).

```bash
cmake -S . -B build
cmake --build build
./build/skeleton_quest
```

The game saves to `save.txt` in the directory you run it from.

## How to play

See the [user manual](docs/USER_MANUAL.md).

## Project structure

```
src/
  main.cpp             Main menu, game loop and combat
  Player.*             Player stats, levelling, healing and special attack
  CharacterCreate.cpp  Character creation screens
  Monster.*            Enemy types, random encounters and the boss
  Area.*               Travel between areas
  Store.*              Shop
  SaveSystem.*         Save/load
  Input.*              Validated console input (numbers, yes/no, text)
  Art.*                ASCII art
docs/
  USER_MANUAL.md
```

## Credits

Originally built as a three-person university project by Paul Blake, Charlie Lambe and Callum Keogh. Refactored and extended by Paul Blake.
