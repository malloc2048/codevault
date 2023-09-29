#include <gtest/gtest.h>
#include "arrays/array.h"

TEST(ArraysTest, FirstDuplicate) {
    ASSERT_EQ(3, Array::first_duplicate(std::vector<int>{ 2, 1, 3, 5, 3, 2 }));
}

TEST(ArraysTest, FirstNotRepeatingCharacter) {
    ASSERT_EQ('c', Array::first_not_repeating_character("abacabad"));
    ASSERT_EQ('_', Array::first_not_repeating_character("bcccccccb"));
}
