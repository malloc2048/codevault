#ifndef CODESIGNAL_CHALLENGE_H
#define CODESIGNAL_CHALLENGE_H

#include <string>

namespace challenge {
    // You are playing an RPG game.
    // Currently your experience points (XP) total is equal to experience.
    // To reach the next level your XP should be at least at threshold.
    // If you kill the monster in front of you, you will gain more experience points in the amount of the reward.
    // Given values experience, threshold and reward, check if you reach the next level after killing the monster.
    bool reachNextLevel(int experience, int threshold, int reward);

    // PEP 8, Style Guide for Python Code, requires a coder to write lines no longer than 79 characters.
    // Given some code line, find out if it satisfies PEP 8 requirements.
    bool pepEight2(std::string line);

    // You've intercepted an encrypted message, and you are really curious about its contents.
    // You were able to find out that the message initially contained only lowercase English letters,
    // and was encrypted with the following cipher:
    //   Let all letters from 'a' to 'z' correspond to the numbers from 0 to 25, respectively.
    //   The number corresponding to the ith letter of the encrypted message is then equal to the sum of numbers
    //     corresponding to the first i letters of the initial unencrypted message modulo 26.
    // Now that you know how the message was encrypted, implement the algorithm to decipher it.
    // Example:
    //   For message = "taiaiaertkixquxjnfxxdh", the output should be
    //     cipher26(message) = "thisisencryptedmessage".
    // The initial message "thisisencryptedmessage" was encrypted as follows:
    //   letter 0: t -> 19 -> t;
    //   letter 1: th -> (19 + 7) % 26 -> 0 -> a;
    //   letter 2: thi -> (19 + 7 + 8) % 26 -> 8 -> i;
    //   etc.
    std::string cipher26(std::string message);

    // Determine if the given number is a power of some non-negative integer
    bool isPower(int n);
}
#endif
