#ifndef PORTFOLIO_DECK_H
#define PORTFOLIO_DECK_H

#include "card.h"

class Deck {
public:
    Deck() = default;
    ~Deck() = default;
    explicit Deck(uint32_t card_count);

    void shuffle();
    void show_deck();
    Card* pop_back();
    Card* pop_front();
    Card* peek_back() const;
    Card* peek_front() const;
    void push_back(Card* card);
    void push_front(Card* card);
    bool operator==(Deck& other);
    bool operator!=(Deck& other);
    uint32_t get_card_count() const;

protected:
    Card* end = nullptr;
    Card* start = nullptr;
    uint32_t card_count = 0;
};
#endif
