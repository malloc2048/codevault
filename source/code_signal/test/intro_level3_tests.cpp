#include "intro/intro.h"
#include <gtest/gtest.h>

TEST(IntroLevel3Test, AdjacentElementsProduct) {
    auto result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "aba", "aa", "ad", "vcd", "aba"
    });
    ASSERT_EQ(result.size(), std::size_t(3));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "aa"
    });
    ASSERT_EQ(result.size(), std::size_t(1));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "abc", "eeee", "abcd", "dcd"
    });
    ASSERT_EQ(result.size(), std::size_t(2));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "a", "abc", "cbd", "zzzzzz", "a", "abcdef", "asasa", "aaaaaa"
    });
    ASSERT_EQ(result.size(), std::size_t(3));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "enyky", "benyky", "yely", "varennyky"
    });
    ASSERT_EQ(result.size(), std::size_t(1));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "abacaba", "abacab", "abac", "xxxxxx"
    });
    ASSERT_EQ(result.size(), std::size_t(1));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "young", "yooooooung", "hot", "or", "not", "come", "on", "fire", "water", "watermelon"
    });
    ASSERT_EQ(result.size(), std::size_t(2));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "onsfnib", "aokbcwthc", "jrfcw"
    });
    ASSERT_EQ(result.size(), std::size_t(1));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "lbgwyqkry"
    });
    ASSERT_EQ(result.size(), std::size_t(1));

    result = Intro::Level3::allLongestStrings(std::vector<std::string>{
        "i"
    });
    ASSERT_EQ(result.size(), std::size_t(1));
}
