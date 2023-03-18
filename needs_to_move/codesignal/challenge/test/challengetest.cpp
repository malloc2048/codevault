#include "challenge.h"
#include <gtest/gtest.h>

TEST(ChallengeTest, ReachNextLevel) {
    ASSERT_TRUE(challenge::reachNextLevel(10, 15, 5));
    ASSERT_TRUE(challenge::reachNextLevel(3, 6, 4));
    ASSERT_TRUE(challenge::reachNextLevel(97, 57, 7));
    ASSERT_TRUE(challenge::reachNextLevel(222, 137, 58));
    ASSERT_TRUE(challenge::reachNextLevel(16, 23, 16));

    ASSERT_FALSE(challenge::reachNextLevel(10, 15, 4));
    ASSERT_FALSE(challenge::reachNextLevel(84, 135, 36));
    ASSERT_FALSE(challenge::reachNextLevel(74, 170, 58));
    ASSERT_FALSE(challenge::reachNextLevel(80, 199, 15));
    ASSERT_FALSE(challenge::reachNextLevel(235, 293, 4));
}

TEST(ChallengeTest, PepEight) {
    ASSERT_TRUE(challenge::pepEight2("b = a + 4"));
}

TEST(ChallengeTest, Cipher26) {
    ASSERT_STREQ("thisisencryptedmessage", challenge::cipher26("taiaiaertkixquxjnfxxdh").c_str());
}

TEST(ChallengeTest, IsPower) {
    ASSERT_FALSE(challenge::isPower(0));
    ASSERT_FALSE(challenge::isPower(-1));
    ASSERT_FALSE(challenge::isPower(1));

    ASSERT_TRUE(challenge::isPower(125));
    ASSERT_FALSE(challenge::isPower(72));
    ASSERT_TRUE(challenge::isPower(100));
    ASSERT_FALSE(challenge::isPower(11));
    ASSERT_TRUE(challenge::isPower(324));
    ASSERT_TRUE(challenge::isPower(256));
    ASSERT_FALSE(challenge::isPower(119));
    ASSERT_TRUE(challenge::isPower(400));
    ASSERT_FALSE(challenge::isPower(350));
    ASSERT_TRUE(challenge::isPower(361));
}
