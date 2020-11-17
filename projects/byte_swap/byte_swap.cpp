#include "byte_swap.h"
#include <gtest/gtest.h>


uint32_t ByteSwap::swap(uint32_t number) {
    uint32_t result = 0;

    result |= (number & 0x000000ffu) << 24u;
    result |= (number & 0x0000ff00u) << 8u;
    result |= (number & 0x00ff0000u) >> 8u;
    result |= (number & 0xff000000u) >> 24u;
    return result;
}


TEST(ByteSwap, SwapBytes) {
    uint32_t expected(0x00efcdab);
    auto result = ByteSwap::swap(0xabcdef00);
    ASSERT_EQ(expected, result);
}
