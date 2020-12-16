// You are playing an RPG game.
// Currently your experience points (XP) total is equal to experience.
// To reach the next level your XP should be at least at threshold.
// If you kill the monster in front of you, you will gain more experience points in the amount of the reward.
// Given values experience, threshold and reward, check if you reach the next level after killing the monster.

#include <map>
#include <gtest/gtest.h>
#include "code_fights.h"

bool CodeFights::reach_next_level(int experience, int threshold, int reward) {
    return experience + reward >= threshold;
}

TEST(CodeFights, ReachNextLevel) {
    ASSERT_TRUE(CodeFights::reach_next_level(10, 15, 5));
    ASSERT_TRUE(CodeFights::reach_next_level(3, 6, 4));
    ASSERT_TRUE(CodeFights::reach_next_level(97, 57, 7));
    ASSERT_TRUE(CodeFights::reach_next_level(222, 137, 58));
    ASSERT_TRUE(CodeFights::reach_next_level(16, 23, 16));

    ASSERT_FALSE(CodeFights::reach_next_level(10, 15, 4));
    ASSERT_FALSE(CodeFights::reach_next_level(84, 135, 36));
    ASSERT_FALSE(CodeFights::reach_next_level(74, 170, 58));
    ASSERT_FALSE(CodeFights::reach_next_level(80, 199, 15));
    ASSERT_FALSE(CodeFights::reach_next_level(235, 293, 4));
}
