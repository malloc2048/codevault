#include <map>
#include <cmath>
#include "code_fights.h"
#include <gtest/gtest.h>

// Determine if the given number is a power of some non-negative integer
bool CodeFights::is_power(int n) {
    if(n < 1 )
        return false;

    for(size_t i = 2; i < n / 2; i++) {
        for(size_t j = 2; j < n / 2; j++) {
            int power = (int)pow(i, j);
            if(power == n)
                return true;
        }
    }
    return false;
}

TEST(CodeFights, IsPower){
    std::map<bool, uint32_t> tests {
        {false, 0}, {false, -1}, {false, 1},
        {true, 125}, {false, 72}, {true, 100},
        {false, 11}, {true, 324}, {true, 256},
        {false, 119}, {true, 400}, {false, 350},
        {true, 361}
    };

    for (auto& test: tests) {
        ASSERT_EQ(test.first, CodeFights::is_power(test.second));
    }
}
