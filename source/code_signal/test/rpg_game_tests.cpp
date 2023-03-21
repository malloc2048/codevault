#include "rpg/rpg_game.h"
#include <gtest/gtest.h>

TEST(RpgGameTest, reach_next_level) {
    ASSERT_TRUE(RpgGame::reach_next_level(10, 15, 5));
    ASSERT_TRUE(RpgGame::reach_next_level(3, 6, 4));
    ASSERT_TRUE(RpgGame::reach_next_level(97, 57, 7));
    ASSERT_TRUE(RpgGame::reach_next_level(222, 137, 58));
    ASSERT_TRUE(RpgGame::reach_next_level(16, 23, 16));

    ASSERT_FALSE(RpgGame::reach_next_level(10, 15, 4));
    ASSERT_FALSE(RpgGame::reach_next_level(84, 135, 36));
    ASSERT_FALSE(RpgGame::reach_next_level(74, 170, 58));
    ASSERT_FALSE(RpgGame::reach_next_level(80, 199, 15));
    ASSERT_FALSE(RpgGame::reach_next_level(235, 293, 4));
}