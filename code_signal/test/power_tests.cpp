#include <gtest/gtest.h>
#include "power/power.h"

TEST(PowerTest, is_power) {
    ASSERT_FALSE(Power::is_power(0));
    ASSERT_FALSE(Power::is_power(-1));
    ASSERT_FALSE(Power::is_power(1));

    ASSERT_TRUE(Power::is_power(125));
    ASSERT_FALSE(Power::is_power(72));
    ASSERT_TRUE(Power::is_power(100));
    ASSERT_FALSE(Power::is_power(11));
    ASSERT_TRUE(Power::is_power(324));
    ASSERT_TRUE(Power::is_power(256));
    ASSERT_FALSE(Power::is_power(119));
    ASSERT_TRUE(Power::is_power(400));
    ASSERT_FALSE(Power::is_power(350));
    ASSERT_TRUE(Power::is_power(361));
}
