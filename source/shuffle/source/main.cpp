#include "deck.h"
#include <string>
#include <iostream>

int main(int argc, char** argv) {
    if(3 == argc) {
        auto num_shuffles = 0;
        auto num_cards = std::stoul(argv[1], nullptr, 10);
        auto max_shuffles = std::stoul(argv[2], nullptr, 10);

        Deck deck(num_cards);
        Deck reference_deck(num_cards);

        std::cout << "shuffling deck with " << num_cards << " cards ..." << std::endl;
        do {
            deck.shuffle();
            num_shuffles++;
        } while(deck != reference_deck && max_shuffles > num_shuffles);

        if(max_shuffles == num_shuffles) {
            std::cout <<
                      "still not back to original order after " <<
                      num_shuffles << " re-shuffles, giving up" << std::endl;
        } else {
            std::cout <<
                      "finished: re-shuffles needed to get back to original order: " <<
                      num_shuffles << std::endl;
        }
    } else {
        std::cout << "usage: " << argv[0] <<
                  " [number of cards in deck] [max re-shuffle attempts]" << std::endl;
    }
    return 0;
}
