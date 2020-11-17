#ifndef PORTFOLIO_SPACEX_H
#define PORTFOLIO_SPACEX_H

#include <string>
#include <vector>

namespace SpaceX {
    // The master launch sequence consists of several independent sequences for different systems.
    // Your goal is to verify that all the individual system sequences are in strictly increasing order.
    // In other words, for any two elements i and j (i < j) of the master launch sequence that belong to the same system
    // (having systemNames[i] = systemNames[j]), their values should be in strictly increasing order
    // (i.e. stepNumbers[i] < stepNumbers[j]).
    // Guaranteed constraints:
    //     1 ≤ systemNames.length ≤ 5 · 10^4
    //     1 ≤ systemNames[i].length ≤ 10
    //     stepNumbers.length = systemNames.length
    //     1 ≤ stepNumbers[i] ≤ 10^9
    bool launch_sequence_checker(const std::vector<std::string>& system_names, const std::vector<int>& step_numbers);

    // SpaceX has built a reliable Earth-Mars communication system that uses n links to transmit messages that are
    // broken into fragments.
    // The messages are sequences of ASCII characters that terminate with '#'.
    // n copies of each fragment are sent, meaning that normally n copies of each fragment are received (one per link).
    // However, some fragments may be lost. It's also possible that they can be corrupted or arrive out of order.
    //
    // Each fragment contains the following data:
    // seq - The sequential number of the fragment in the message. This part of the fragment is never corrupted.
    // fragmentData - A single character from the message contained in the fragment.
    //
    // Implement a function that receives an array of message fragments and reconstructs the original message according
    // to the following rules:
    // For each sequential number, pick the data character that is present in more than 50% of the fragments with that
    // sequential number.
    //   Note that we calculate 50% based on the total number of copies that were sent (which is always equal to n),
    //   while the number of received fragments can be smaller.
    // The last fragment of the message that's been reconstructed according to rule 1 (and no other fragment) contains '#'.
    // There can be no gaps in the message, so all of the fragments numbered 0, 1, 2, ..., <number of the last fragment>
    // should be restored.
    // If the message cannot be reconstructed, return an empty string. Otherwise, return the reconstructed message.
    std::string packet_descrambler(std::vector<int> seq, std::vector<char> fragment_data, int n);
};
#endif
