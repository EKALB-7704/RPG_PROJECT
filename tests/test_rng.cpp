#include "doctest.h"
#include "Rng.h"
#include "Monster.h"
#include "Player.h"

TEST_CASE("Rng::range stays inside its inclusive bounds and hits both ends"){
    Rng rng(42);
    bool saw_lo = false, saw_hi = false;
    for (int i = 0; i < 1000; ++i) {
        int r = rng.range(4, 9);
        CHECK(r >= 4);
        CHECK(r <= 9);
        saw_lo = saw_lo || r == 4;
        saw_hi = saw_hi || r == 9;
    }
    CHECK(saw_lo);
    CHECK(saw_hi);
}

TEST_CASE("Rng::range with equal bounds always returns that value"){
    Rng rng(1);
    for (int i = 0; i < 10; ++i)
        CHECK(rng.range(7, 7) == 7);
}

TEST_CASE("the same seed gives the same sequence"){
    Rng a(1234), b(1234);
    for (int i = 0; i < 100; ++i)
        CHECK(a.range(0, 1000) == b.range(0, 1000));
}

TEST_CASE("returnOpponent gives the boss from level 5, a regular monster below"){
    Rng rng(7);
    CHECK(returnOpponent(kBossLevel, rng).getIsBoss());
    for (int i = 0; i < 50; ++i)
        CHECK_FALSE(returnOpponent(1, rng).getIsBoss());
}

TEST_CASE("specialAttack deals attack + 4..9 and spends stamina"){
    Rng rng(99);
    Player p;
    p.current_attack = 10;
    p.stamina = 1;
    int dmg = p.specialAttack(rng);
    CHECK(dmg >= 14);
    CHECK(dmg <= 19);
    CHECK(p.stamina == 0);
    CHECK(p.specialAttack(rng) == 0);  // out of stamina
}
