#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"


TEST_CASE("testing gainEXP function"){
    Player test_player;
    test_player.base_health = 40;
    test_player.maxHP = 40;
    test_player.current_health = 40;

    test_player.gainExp(100);

    CHECK(test_player.level == 3);
    CHECK(test_player.exp == 40);
    CHECK(test_player.current_health == 60);
    CHECK(test_player.maxHP == 60);
    CHECK(test_player.maxStamina == 3);
}

TEST_CASE("checking health cap and potion tracking"){
    Player test_player;
    test_player.maxHP = 40;
    test_player.current_health = 35;
    test_player.potion = 1;

    test_player.heal();
    CHECK(test_player.current_health == 40);
    CHECK(test_player.potion == 0);

    test_player.heal();
    CHECK(test_player.current_health == 40);
    CHECK(test_player.potion == 0);
}