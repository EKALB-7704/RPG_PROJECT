# Skeleton Quest: User Manual

The aim of the game is to battle enemies, level up, and defeat the Skeleton King.

Every menu takes a number. If you type something invalid, the game asks again.

## Main menu

1. **New Game:** create a new character
2. **Load Game:** continue from `save.txt`. If there is no save, or it can't be read, a new game starts instead.

## Character creation

1. **Name:** any name, spaces allowed.
2. **Age:** between 5 and 100.
3. **Gender**
4. **Race:** decides where you start.

   | Race   | Starting area |
   |--------|---------------|
   | Goblin | Swamp         |
   | Elf    | Forest        |
   | Dwarf  | Mountains     |
   | Human  | Plains        |

5. **Class:** decides your starting stats.

   | Class   | Health | ATK | DEF |
   |---------|--------|-----|-----|
   | Warrior | 40     | 7   | 15  |
   | Mage    | 30     | 12  | 8   |
   | Archer  | 25     | 10  | 12  |

6. **Quest:** accept the quest to defeat the Skeleton King.

You confirm each choice with Y or N before moving on. Every character starts with 3 potions and 0 gold.

## World map

1. Fight
2. Town (shop)
3. Stats
4. Travel
5. Save game
6. Quit game

## Fight

Each area has one enemy to defeat. Once you beat it, travel to a different area to find another.

Each turn, choose:

1. **Attack:** deal between 1 and your ATK in damage.
2. **Heal:** drink a potion to restore up to 12 HP.
3. **Special attack:** deal your ATK plus 4–9 bonus damage. Uses 1 stamina.

The enemy then attacks. Your defence reduces the damage you take by DEF ÷ 6.

Defeating an enemy gives you XP and gold. If your health reaches 0, the game is over.

### Enemies

| Enemy            | HP  | Max hit | XP  | Gold |
|------------------|-----|---------|-----|------|
| Skeleton Minion  | 30  | 4       | 10  | 15   |
| Skeleton Soldier | 35  | 6       | 15  | 20   |
| Skeleton Knight  | 45  | 10      | 25  | 30   |
| Skeleton Giant   | 55  | 7       | 30  | 40   |

## Levelling

You need **level × 20** XP to reach the next level. Leftover XP carries over, so one big fight can give you several levels.

Each level gives you:
- +10 max HP
- +2 ATK
- +2 DEF
- +1 max stamina

Levelling up also fully restores your health and stamina.

## Town (shop)

| Item            | Price   | Effect         |
|-----------------|---------|----------------|
| Potion          | 10 gold | +1 potion      |
| Defence upgrade | 40 gold | +5 DEF         |
| Attack upgrade  | 50 gold | +5 ATK         |

## Stats

Shows your attack, defence, health, level and gold.

## Travel

Choose one of the four areas. Travelling to a new area gives you a new enemy to fight. Travelling to the area you are already in does nothing.

## Save

Saves your character to `save.txt` in the folder you ran the game from. Saves made before the 2026 overhaul use an older format and won't load.

## Boss fight

Once you reach **level 5**, every fight is against the **Skeleton King** (200 HP, max hit 20). Defeat him to win the game. If he defeats you, the game is over.

To change the level he appears at, edit `kBossLevel` in `src/Monster.h`.

Enjoy the game!
