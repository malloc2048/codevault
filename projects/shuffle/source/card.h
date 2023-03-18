#ifndef PORTFOLIO_CARD_H
#define PORTFOLIO_CARD_H

#include <cstdint>

struct Card {
    uint32_t value;
    Card* next = nullptr;
    Card* previous = nullptr;

    Card(uint32_t value) : value(value){}
};
#endif
