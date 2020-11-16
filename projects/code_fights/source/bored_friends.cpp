#include <map>
#include <gtest/gtest.h>
#include "code_fights.h"

// Two friends Davit and Tigran were bored. So they decided to play a game.?
// Rules of the game are as follows: First, they choose an integer n. Then they take successive turns, starting with Davit.
// In each turn, a player chooses an integer from 1 to 8 (inclusive) and subtracts it from n.
// The player wins if after his turn, n becomes 0.
// Your task is to determine whether Davit will win or not, assuming that both players play optimally.
// Examples
// For n = "5", the output should be boredFriends(n) = true. Davit can make n = 0 after his first move.
// For n = "9", the output should be boredFriends(n) = false. Davit can't win during his first move,
// but no matter what number he chooses, Tigran can win on the next move.

decltype(int()) WINNING_MULTIPLE { 9 };

bool CodeFights::bored_friends(const std::string& n) {
    auto value = std::strtol(n.c_str(), nullptr, 10);
    return (value == 0) || (value % WINNING_MULTIPLE != 0);
}

TEST(CodeFights, BoredFriends) {
    std::map<std::string, bool> tests {
        {"5", true},
        {"9", false},
        {"126", false},
        {"10", true},
        {"1001", true},
        {"abc", true},
    };

    for (auto& test: tests) {
        ASSERT_EQ(CodeFights::bored_friends(test.first), test.second);
    }
}
