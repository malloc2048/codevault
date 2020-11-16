#include "deck.h"
#include <iostream>

Deck::Deck(uint32_t card_count) : card_count(card_count){
    for(auto i = 0; i < card_count; i++) {
        push_back(new Card(i));
    }
}

void Deck::shuffle() {
    Card* new_end = nullptr;
    Card* new_start = nullptr;

    while (nullptr != start) {
        auto current = pop_front();
        if(nullptr == new_end) {
            new_end = current;
        }

        current->next = new_start;
        current->previous = nullptr;
        new_start = current;

        if(nullptr != start) {
            current = pop_front();
            push_back(current);
        }
    }
    start = new_start;
    end = new_end;
}

void Deck::show_deck() {
    auto card = start;
    while(nullptr != card) {
        std::cout << card->value << " ";
        card = card->next;
    }
    std::cout << std::endl;
}

Card *Deck::pop_back() {
    auto card = end;
    if(nullptr != end) {
        end = end->previous;
        end->next = nullptr;
    }
    return card;
}

Card *Deck::pop_front() {
    auto card = start;
    if(nullptr != start) {
        start = start->next;
        if(nullptr != start) {
            start->previous = nullptr;
        }
    }
    return card;
}

Card *Deck::peek_back() const {
    return end;
}

Card *Deck::peek_front() const {
    return start;
}

void Deck::push_back(Card *card) {
    if(nullptr != card) {
        if(nullptr == start)
            start = card;
        if(nullptr != end)
            end->next = card;

        card->previous = end;
        card->next = nullptr;
        end = card;
    }
}

void Deck::push_front(Card *card) {
    if(nullptr != card) {
        if(nullptr == end )
            end = card;
        if(nullptr != start)
            start->previous = card;
        card->next = start;
        card->previous = nullptr;
        start = card;
    }
}

bool Deck::operator==(Deck &other) {
    bool retval = false;

    if(other.get_card_count() == card_count) {
        retval = true;

        auto otherCard = other.peek_front();
        auto card = start;
        while(nullptr != otherCard && nullptr != card && retval) {
            retval &= otherCard->value == card->value;
            otherCard = otherCard->next;
            card = card->next;
        }
    }
    return retval;
}

bool Deck::operator!=(Deck &other) {
    return !this->operator ==(other);
}

uint32_t Deck::get_card_count() const {
    return card_count;
}
