#include "level1.h"
#include <gtest/gtest.h>

TEST(IntroLevel1Test, AddTest) {
    ASSERT_EQ(level1::add(1, 2), 3);
    ASSERT_EQ(level1::add(2, -39), -37);
    ASSERT_EQ(level1::add(99, 100), 199);
    ASSERT_EQ(level1::add(-100, 100), 0);
    ASSERT_EQ(level1::add(0, 1000), 1000);
    ASSERT_EQ(level1::add(-1000, -1000), -2000);
}

TEST(IntroLevel1Test, CentryFromYear) {
    ASSERT_EQ(level1::centuryFromYear(1905), 20);
    ASSERT_EQ(level1::centuryFromYear(1700), 17);
    ASSERT_EQ(level1::centuryFromYear(1988), 20);
    ASSERT_EQ(level1::centuryFromYear(2000), 20);
    ASSERT_EQ(level1::centuryFromYear(2001), 21);
    ASSERT_EQ(level1::centuryFromYear(200), 2);
    ASSERT_EQ(level1::centuryFromYear(374), 4);
    ASSERT_EQ(level1::centuryFromYear(45), 1);
    ASSERT_EQ(level1::centuryFromYear(8), 1);
}

TEST(IntroLevel1Test, CheckPalindrome) {
    ASSERT_TRUE(level1::checkPalindrome("a"));
    ASSERT_TRUE(level1::checkPalindrome("z"));
    ASSERT_TRUE(level1::checkPalindrome("aabaa"));
    ASSERT_TRUE(level1::checkPalindrome("abacaba"));
    ASSERT_TRUE(level1::checkPalindrome("hlbeeykoqqqokyeeblh"));
    ASSERT_TRUE(level1::checkPalindrome("hlbeeykoqqqqokyeeblh"));

    ASSERT_FALSE(level1::checkPalindrome("az"));
    ASSERT_FALSE(level1::checkPalindrome("abac"));
    ASSERT_FALSE(level1::checkPalindrome("aaabaaaa"));
    ASSERT_FALSE(level1::checkPalindrome("zzzazzazz"));
}
