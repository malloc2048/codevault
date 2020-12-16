#ifndef PORTFOLIO_BYTE_SWAPPER_H
#define PORTFOLIO_BYTE_SWAPPER_H

#include <cstdint>

class ByteSwapper {
public:
    ByteSwapper() = default;
    ~ByteSwapper() = default;

    static uint32_t swap(uint32_t number);
};
#endif
