#include "byteswapper.h"
#include "gtest/gtest.h"

TEST(RaytheonTest, SwapBytes) {
    uint32_t expected(0x00efcdab);
    auto result = ByteSwapper::swap(0xabcdef00);
    ASSERT_EQ(expected, result);
}
