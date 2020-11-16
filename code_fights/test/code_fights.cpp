#include <map>
#include "code_fights.h"
#include <gtest/gtest.h>

TEST(FirstDuplicateTest, Tests){
    std::map<uint32_t, std::vector<int>> tests {
        {3, {2, 1, 3, 5, 3, 2}}, {-1, {2, 4, 3, 5, 1}}, {-1, {1}},
        {2, {2, 2}}, {-1, {2, 1}}, {-1, {2, 1, 3}}, {3, {2, 3, 3}}, {3, {3, 3, 3}},
        {6, {8, 4, 6, 2, 6, 4, 7, 9, 5, 8}}, {-1, {10, 6, 8, 4, 9, 1, 7, 2, 5, 3}}, {1, {1, 1, 2, 2, 1}}
    };

    for (auto& test: tests) {
        ASSERT_EQ(test.first, CodeFights::first_duplicate(test.second));
    }
}

TEST(FirstNotRepeatingCharacterTest, Tests) {
    std::vector<std::pair<char, std::string>> tests {
        {'c', "abacabad"},
        {'_', "abacabaabacaba"},
        {'z', "z"},
        {'c', "bcb"},
        {'_', "bcccccccb"},
        {'d', "abcdefghijklmnopqrstuvwxyziflskecznslkjfabe"},
        {'_', "zzz"},
        {'y', "bcccccccccccccyb"},
        {'d', "xdnxxlvupzuwgigeqjggosgljuhliybkjpibyatofcjbfxwtalc"},
        {'g', "ngrhhqbhnsipkcoqjyviikvxbxyphsnjpdxkhtadltsuxbfbrkof"},
        {'_', ""}
    };

    for (auto& test: tests) {
        ASSERT_EQ(test.first, CodeFights::first_not_repeating_character(test.second));
    }
}

TEST(RotateImageTest, Test) {
    std::vector<int> expectedRow1 = {7, 4, 1};
    std::vector<int> expectedRow2 = {8, 5, 2};
    std::vector<int> expectedRow3 = {9, 6, 3};
    std::vector<std::vector<int>> expectedArray = {expectedRow1, expectedRow2, expectedRow3};

    std::vector<int> row1 = {1, 2, 3};
    std::vector<int> row2 = {4, 5, 6};
    std::vector<int> row3 = {7, 8, 9};
    std::vector<std::vector<int>> array = {row1, row2, row3};

    ASSERT_EQ(expectedArray, CodeFights::rotate_image(array));
}
