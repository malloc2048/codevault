#include <map>
#include <algorithm>
#include "code_fights.h"
#include <gtest/gtest.h>

char CodeFights::first_not_repeating_character(const std::string& s) {
    int nextRepeatedIdx = 0;
    std::vector<int> counts(26, 0);
    std::vector<char> notRepeatedChars(26, '_');

    for(auto character: s) {
        counts[character - 'a']++;
        if(counts[character - 'a'] == 1) {
            notRepeatedChars[nextRepeatedIdx++] = character;
        }
        else {
            auto a = std::find(notRepeatedChars.begin(), notRepeatedChars.end(), character);
            if(notRepeatedChars.end() != a)
                *a = '_';
        }
    }

    for(auto item: notRepeatedChars){
        if(item != '_'){
            return item;
        }
    }
    return '_';
}

TEST(CodeFights, FirstNotRepeatingCharacter) {
    std::vector<std::pair<char, std::string>> tests {
        {'c', "abacabad"},
        {'_', "abacabaabacaba"},
        {'z', "z"},
        {'c', "bcb"},
        {'_', "bcccccccb"},
        {'d', "abcdefghijklmnopqrstuvwxyziflskecznslkjfabe"},
        {'_', "zzz"},
        {'y', "bcccccccccccccyb"},
        {'d', "xdnxxlvupzuwgigeqjggosgljuhliybkjpibyatofcjbfxwtalc"},
        {'g', "ngrhhqbhnsipkcoqjyviikvxbxyphsnjpdxkhtadltsuxbfbrkof"},
        {'_', ""}
    };

    for (auto& test: tests) {
        ASSERT_EQ(test.first, CodeFights::first_not_repeating_character(test.second));
    }
}
