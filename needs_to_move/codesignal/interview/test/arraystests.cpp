#include <gtest/gtest.h>
#include "arrays.h"

TEST(InterviewArraysTest, FirstDuplicate) {
    ASSERT_EQ(3, interview::firstDuplicate(std::vector<int>{ 2, 1, 3, 5, 3, 2 }));
}

TEST(InterviewArraysTest, FirstNotRepeatingCharacter) {
    ASSERT_EQ('c', interview::firstNotRepeatingCharacter("abacabad"));
    ASSERT_EQ('_', interview::firstNotRepeatingCharacter("bcccccccb"));
}
