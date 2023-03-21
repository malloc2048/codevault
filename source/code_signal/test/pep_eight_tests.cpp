#include "pep_eight/pep_eight.h"
#include <gtest/gtest.h>

TEST(PepEightTest, PepEightTwo) {
    ASSERT_TRUE(PepEight::pep_eight_two("b = a + 4"));
}
