#include "byteswapper.h"

uint32_t ByteSwapper::swap(uint32_t number) {
    uint32_t result = 0;

    result |= (number & 0x000000ff) << 24;
    result |= (number & 0x0000ff00) << 8;
    result |= (number & 0x00ff0000) >> 8;
    result |= (number & 0xff000000) >> 24;

    return result;
}
