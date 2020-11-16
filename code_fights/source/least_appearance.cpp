#include <map>
#include <gtest/gtest.h>
#include "code_fights.h"

std::vector<int> CodeFights::least_appearance(std::vector<std::vector<int>> choices) {
    std::vector<int> result;
    std::map<int, int> numberCounts;

    for (auto &item: choices) {
        int count1 = numberCounts[item.front()];
        int count2 = numberCounts[item.back()];

        if (count1 < count2) {
            numberCounts[item.front()]++;
            result.push_back(item.front());
        } else if (count1 > count2) {
            numberCounts[item.back()]++;
            result.push_back(item.back());
        } else {
            int minNum = item.front();
            if (item.front() > item.back()) {
                minNum = item.back();
            }
            numberCounts[minNum]++;
            result.push_back(minNum);
        }
    }
    return result;
}

TEST(CodeFights, LeastAppearance) {
    std::map<std::vector<int>, std::vector<int>> tests {
        {{1}, {1, 2}}
    };
}
