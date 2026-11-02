# Skeleton Quest — Overhaul Plan

Working document for the Phase 2 overhaul. Self-contained: everything needed to
pick the work up on a fresh machine is here.

- **Phase 1 (done, merged in #1):** moved to `src/` + CMake, added validated
  input, a versioned save file, and rewrote the README and user manual.
- **Phase 2A (in progress):** make the codebase testable.
- **Phase 2B–2E (planned):** restructure, then fix the game itself.

---

## Current status

| Step | State |
|---|---|
| 2A.1 — library/executable split, combat moved out of `main.cpp` | **done** (`00b4327`) |
| 2A.1b — fix clang `-Werror` build | **done** (`ecfda28`) |
| 2A.2 — test harness + first tests | todo |
| 2A.3 — `Rng` seam | todo |
| 2A.4 — `Io` seam | todo |
| 2A.5 — CI + sanitizers | todo |

Build and run:

```bash
cmake -S . -B build
cmake --build build
./build/skeleton_quest
```

Both gcc and clang build the tree warning-free under
`-Wall -Wextra -Wpedantic -Wshadow -Werror`. Keep it that way.

### What 2A.1 changed

`CMakeLists.txt` now declares three targets:

- `project_warnings` — an `INTERFACE` target holding the warning flags, so they
  are declared once rather than per target.
- `game_core` — a static library with all game logic. **This is the target the
  test binary links against**; that was the whole point of the split.
- `skeleton_quest` — a thin executable: `main.cpp` holds only `showMap()` and
  the menu loop.

`battle()` and `BattleResult` moved from `main.cpp` to `src/Battle.{h,cpp}`,
token-for-token identical apart from renaming the local `enemy_m` to
`new_enemy`. `returnOpponent` now takes `int level` by value.

---

## Review findings (the reason for all of this)

Numbered so the commits below can refer to them.

### Correctness

1. **Confirmed crash.** `Battle.cpp` does `rand() % player.current_attack`,
   which divides by zero when attack is 0. Reachable because the save loader
   validates the header and stream state but **not a single value**. Editing
   attack to 0 in `save.txt` kills the game with SIGFPE (exit 136).
2. **The save format drops four fields.** `SaveSystem.cpp` never writes `age`,
   `gender`, `race` or `Class`. After a load, `Class` and `race` are 0, so a
   loaded player can never recompute stats from their class, and calling
   `starting_stats()` on one would zero every stat.
3. **Permadeath with no off-ramp.** Defeat is a bare `return 0` in `main.cpp`.
   No retry, no offer to reload.
4. **`rand()` everywhere**, seeded `srand(time(0))`. Modulo-biased and
   impossible to test deterministically.
5. **Dead code.** `Player::Character_Readback()` and `Area::current_area()` are
   defined and never called — which is why age and gender are collected at
   character creation and then never displayed anywhere.
6. **The quest prompt is theatre.** `CharacterCreate.cpp` asks whether you
   accept the quest, prints a line, discards the answer.

### Architecture

7. **`Player` is a god object** — data, UI rendering (`stats_readback`) *and*
   the character-creation flow (`Name()`, `Age()`, `Race()`, `Class_()`). Model
   and view are fused to stdin/stdout, so none of it is unit-testable.
8. **No invariants.** Every field public and mutable; `Store` mutates the player
   through raw `int&` references. Nothing can enforce "health never exceeds
   maxHP".
9. **Classes used as namespaces.** `store`, `Area` and `Art` are stateless (bar
   three prices). Naming is four conventions at once: `store` vs `Area`,
   `Class`, `Display_Monster`, `p_race`, `kill_count`.
10. **Content hardcoded across files.** Monsters in `Monster.cpp`, areas in
    `Area.cpp`, prices in `Store.h`. Class stats live in *two* places — the
    display table and `starting_stats()`, both in `CharacterCreate.cpp`. They
    currently agree; nothing keeps them that way.
11. **One art asset for every enemy.** `Display_Monster` prints the same
    skeleton for the Minion and the Skeleton King alike, at a hardcoded
    106-character banner width.
12. **Include hygiene.** `Monster.h` pulls in unused `<thread>`/`<chrono>` and
    uses include guards while every other header uses `#pragma once`.
    `Monster.cpp` includes `<iostream>` twice.

### Balance — simulated over 20k runs per class

| Class | Survives the grind | Beats the boss |
|---|---|---|
| Warrior | 80.4% | 80.4% |
| Mage | 75.3% | 75.1% |
| Archer | 68.2% | 68.1% |

**Nobody who reaches the boss loses.** Those columns are identical to within
rounding: the Skeleton King is a formality, and every loss in the game is a
random death during the grind.

The cause is the special attack. It deals `attack + 4..9`; a normal attack deals
`1..attack`. The special is *strictly better* at every stat level, so combat has
no tactical decision — spam special, then attack. And because stamina refills to
`level` on every level-up, you reach the boss with 5 unused specials worth ~130
of his 200 HP, free.

Supporting issues:

13. **DEF is almost inert.** `dmg - current_defence / 6` means the Warrior's
    15 DEF removes 2 damage.
14. **Level-up full-heals**, so potions barely matter before the boss.
15. **Warrior dominates despite the lowest attack** (7 vs the Archer's 10).
    Level-ups add a flat `+2` ATK to everyone, compressing the attack gap, while
    the HP gap *compounds* via `maxHP = base_health + 10 * (level - 1)`. The
    glass cannon is strictly worse at both jobs.
16. **The level-5 boss gate is a cliff.** At level 5 *every* encounter is the
    boss, so farming stops exactly when you want resources.
17. **`area_cleared` is not the limit it looks like** — travel back and forth and
    it resets, so it is friction, not a constraint.
18. The boss drops 4000 gold one line before the game ends.

---

## Phase 2A — remaining commits

Each commit should build and play on its own.

### 2A.2 — Test harness

Prove the harness works against code you have not touched yet.

Fetch [doctest](https://github.com/doctest/doctest)'s single header into
`third_party/doctest.h` (lighter and faster to compile than Catch2; the API is
close enough that the choice stays reversible). Then append to `CMakeLists.txt`:

```cmake
enable_testing()
add_executable(tests tests/test_player.cpp)
target_link_libraries(tests PRIVATE game_core project_warnings)
target_include_directories(tests SYSTEM PRIVATE third_party)
add_test(NAME unit COMMAND tests)
```

`SYSTEM` on that include directory matters — without it `-Werror` will fail the
build over warnings inside doctest's own header.

Write these two first, because they need **no production changes**:
`Player::gainExp` and `Player::heal` are already pure logic over public fields.

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"

TEST_CASE("gainExp levels up more than once from one large reward") {
    Player p;
    p.base_health = 40; p.maxHP = 40; p.current_health = 40;
    p.current_attack = 7; p.current_defence = 15;
    p.gainExp(100);          // needs 20 then 40 -> level 3, 40 left over
    CHECK(p.level == 3);
    CHECK(p.exp == 40);
    CHECK(p.maxHP == 60);    // base_health + 10 * (level - 1)
}

TEST_CASE("heal clamps at maxHP and is a no-op with no potions") {
    Player p;
    p.maxHP = 40; p.current_health = 35; p.potion = 1;
    p.heal();
    CHECK(p.current_health == 40);   // clamped, not 47
    CHECK(p.potion == 0);
    p.heal();                        // no potions left
    CHECK(p.current_health == 40);
}
```

That first test pins the `while (exp >= level * 20)` loop, the carryover
arithmetic and the stat recomputation — the three things most likely to break
during the 2D rebalance. A green run also confirms the library split works.

### 2A.3 — The `Rng` seam

Deterministic combat, and modulo bias gone. There are only **four** `rand()`
call sites.

```cpp
// src/Rng.h
#pragma once
#include <cstdint>
#include <random>

class Rng {
public:
    explicit Rng(std::uint32_t seed) : engine_(seed) {}
    int range(int lo, int hi);   // inclusive at both ends
private:
    std::mt19937 engine_;
};
```

Prefer an inclusive `range(lo, hi)` over a `next(n)` style: it makes the current
off-by-ones explicit at each call site.

| Current | Becomes |
|---|---|
| `rand() % 10` (`Monster.cpp:42`) | `rng.range(0, 9)` |
| `rand() % 6 + 4` (`Player.cpp:20`) | `rng.range(4, 9)` |
| `rand() % player.current_attack + 1` (`Battle.cpp`) | `rng.range(1, player.current_attack)` |
| `rand() % new_enemy.attack + 1` (`Battle.cpp`) | `rng.range(1, new_enemy.attack)` |

Thread it by reference — `battle(Player&, Rng&)`,
`Player::specialAttack(Rng&)`, `getRandomMonster(Rng&)` — and construct the one
instance in `main`. **Do not** make it a global or a singleton; that hands back
the untestability this is buying out.

`std::uniform_int_distribution<int>(1, 0)` is undefined behaviour, so put
`assert(lo <= hi)` in `range`. Note this does *not* fix finding 1 — an attack of
0 from a corrupt save still breaks, it just fails loudly in a debug build
instead of SIGFPE-ing. The real fix is save validation in 2D.

Free bonus: a `--seed N` argument in `main` now costs almost nothing and makes
manual bug reproduction possible.

### 2A.4 — The `Io` seam

The real work of 2A. Note that `readLine` is already the single choke point for
all input (one `std::cin` site in the whole codebase), which is what makes this
tractable.

**Only two methods need to be virtual:**

```cpp
// src/Io.h
#pragma once
#include <string>

class Io {
public:
    virtual ~Io() = default;
    virtual void print(const std::string& text) = 0;
    virtual std::string readLine(const std::string& prompt) = 0;

    // Non-virtual: pure logic over the two primitives above.
    int readInt(const std::string& prompt, int min, int max);
    bool readYesNo(const std::string& prompt);
};
```

`readInt` and `readYesNo` are validation logic, not I/O. Keeping them
non-virtual in the base means the careful parsing already in `Input.cpp` is
written once, tested once, and shared by the console and the test double alike.

`ConsoleIo` is the existing `Input.cpp` body. The double:

```cpp
class ScriptedIo : public Io {
public:
    explicit ScriptedIo(std::vector<std::string> lines)
        : lines_(std::move(lines)) {}
    void print(const std::string& t) override { out_ += t; }
    std::string readLine(const std::string&) override {
        if (next_ >= lines_.size())
            throw std::runtime_error("script exhausted");
        return lines_[next_++];
    }
    const std::string& output() const { return out_; }
private:
    std::vector<std::string> lines_;
    std::size_t next_ = 0;
    std::string out_;
};
```

Now the input validation that was previously unreachable becomes testable: feed
`{"abc", "5x", "99", "3"}` and assert it returns 3 after rejecting three bad
inputs.

**The gotcha that will bite:** there are 174 `std::cout` sites. Do **not**
convert them all now. Convert `Battle`, `Player`, `Store` and `Input` — the
places with logic worth testing. Leave `Art.cpp`'s 37 lines of pure decoration
on `std::cout`; it has no logic, so a seam buys nothing. `CharacterCreate.cpp`'s
48 sites can wait for 2B, when that file is being restructured anyway. Letting
this step balloon into a 900-line rewrite before any tests exist is the main way
Phase 2A fails.

Keep `std::exit(0)` (currently `Input.cpp:14`) inside `ConsoleIo` only, never in
the shared non-virtual helpers, or a test hitting EOF will kill the test runner
mid-suite.

Combat's final signature becomes `BattleResult battle(Player&, Rng&, Io&)`. A
fixed seed plus a scripted input then makes a whole fight reproducible
assertion-by-assertion.

### 2A.5 — CI and sanitizers

`.github/workflows/build.yml`:

```yaml
name: build
on: [push, pull_request]
jobs:
  build:
    runs-on: ubuntu-latest
    strategy:
      matrix:
        cxx: [g++, clang++]
    steps:
      - uses: actions/checkout@v4
      - run: cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
        env: { CXX: "${{ matrix.cxx }}" }
      - run: cmake --build build
      - run: ctest --test-dir build --output-on-failure
```

For sanitizers use a CMake **option**, not `CMakePresets.json`: presets need
CMake 3.19+ and `cmake_minimum_required` here declares 3.16.

```cmake
option(ENABLE_SANITIZERS "Build with ASan and UBSan" OFF)
if(ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(project_warnings INTERFACE
        -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(project_warnings INTERFACE
        -fsanitize=address,undefined)
endif()
```

Add a third CI job running `-DENABLE_SANITIZERS=ON`. That is what will catch the
class of bug behind finding 1 automatically from here on.

### One test to write deliberately red

Once the harness is up, write the save/load round-trip test: build a player with
a known age, gender, race and class, save, load into a fresh `Player`, compare
every field. **It will fail**, because of finding 2. Mark it `[.]` (doctest's
skip decorator) with a comment pointing at Phase 2D.

That turns "the save format drops four fields" from a note into a failing
assertion with an address, and gives 2D an unambiguous definition of done.

---

## Phase 2B — Separate model from presentation

Addresses findings 5, 7, 8, 9, 12.

1. `Player` becomes data + rules (`gainExp`, `heal`, `applyDamage`) with
   enforced invariants and private fields.
2. Move the creation flow out of `Player` into a `CharacterCreation` module that
   *returns* a built `Player`; move the readbacks into a view module.
3. Collapse `store` / `Area` / `Art` into namespaced free functions.
4. One naming convention throughout; `#pragma once` everywhere; drop unused
   includes; either delete the dead functions or wire them in — show
   `Character_Readback()` after creation so age and gender finally mean
   something, and hook `current_area()` into the map screen.

## Phase 2C — Data-driven content

Addresses findings 10, 11.

1. One table for monsters, areas, class stats and prices (`constexpr` tables in
   a header now; JSON later if modding is wanted). Generate the class-stats
   display table from that same data so finding 10 cannot recur.
2. Per-enemy art keyed by id, boss included; derive the banner width from the
   art instead of hardcoding 106.

## Phase 2D — Fix the game

Addresses findings 1, 2, 3, 6, 13–18. This is the part a player notices.

1. **Harden save/load:** validate and clamp every field, reject nonsense, save
   `age`/`gender`/`race`/`Class`, bump to `SKELETON_QUEST_SAVE 2` with a
   migration from v1. Closes finding 1 at its source and turns the red
   round-trip test green.
2. **Death offers a choice:** load last save / new game / quit.
3. **Rebalance against the simulation, not against vibes:**
   - Make the special attack a *trade-off*, not a free upgrade — higher damage
     but a real cost (miss chance, self-stagger, or stamina that only
     regenerates by resting).
   - Percentage-based damage reduction so DEF is a real stat.
   - Drop the free full heal on level-up.
   - Gate the boss behind a quest flag or a dedicated area rather than a level,
     so farming is not severed at the threshold.
   - Scale level-up gains by class instead of a flat `+2`, so the Archer has a
     reason to exist.
   - Re-run the simulation and target a win rate actually chosen on purpose.
4. Make the quest choice affect something, or cut the screen.

## Phase 2E — Stretch

Inventory and equipment instead of permanent stat bumps; multiple save slots;
area-appropriate enemies instead of skeletons everywhere; ANSI colour.
