#ifndef CODESIGNAL_BYTESWAPPER_H
#define CODESIGNAL_BYTESWAPPER_H

#include <cstdint>

class ByteSwapper {
public:
    ByteSwapper() = default;
    ~ByteSwapper() = default;

    static uint32_t swap(uint32_t number);
};
#endif
