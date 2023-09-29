#include "intro/intro.h"
#include <gtest/gtest.h>

TEST(IntroLevel1Test, Add) {
    ASSERT_EQ(Intro::Level1::add(1, 2), 3);
    ASSERT_EQ(Intro::Level1::add(2, -39), -37);
    ASSERT_EQ(Intro::Level1::add(99, 100), 199);
    ASSERT_EQ(Intro::Level1::add(-100, 100), 0);
    ASSERT_EQ(Intro::Level1::add(0, 1000), 1000);
    ASSERT_EQ(Intro::Level1::add(-1000, -1000), -2000);
}

TEST(IntroLevel1Test, CentryFromYear) {
    ASSERT_EQ(Intro::Level1::century_from_year(1905), 20);
    ASSERT_EQ(Intro::Level1::century_from_year(1700), 17);
    ASSERT_EQ(Intro::Level1::century_from_year(1988), 20);
    ASSERT_EQ(Intro::Level1::century_from_year(2000), 20);
    ASSERT_EQ(Intro::Level1::century_from_year(2001), 21);
    ASSERT_EQ(Intro::Level1::century_from_year(200), 2);
    ASSERT_EQ(Intro::Level1::century_from_year(374), 4);
    ASSERT_EQ(Intro::Level1::century_from_year(45), 1);
    ASSERT_EQ(Intro::Level1::century_from_year(8), 1);
}

TEST(IntroLevel1Test, CheckPalindrome) {
    ASSERT_TRUE(Intro::Level1::check_palindrome("a"));
    ASSERT_TRUE(Intro::Level1::check_palindrome("z"));
    ASSERT_TRUE(Intro::Level1::check_palindrome("aabaa"));
    ASSERT_TRUE(Intro::Level1::check_palindrome("abacaba"));
    ASSERT_TRUE(Intro::Level1::check_palindrome("hlbeeykoqqqokyeeblh"));
    ASSERT_TRUE(Intro::Level1::check_palindrome("hlbeeykoqqqqokyeeblh"));

    ASSERT_FALSE(Intro::Level1::check_palindrome("az"));
    ASSERT_FALSE(Intro::Level1::check_palindrome("abac"));
    ASSERT_FALSE(Intro::Level1::check_palindrome("aaabaaaa"));
    ASSERT_FALSE(Intro::Level1::check_palindrome("zzzazzazz"));
}
