#include <map>
#include "code_fights.h"
#include <gtest/gtest.h>

int CodeFights::first_duplicate(std::vector<int> a) {
    int duplicateIndex = -1;

    std::map<int, int> found;
    for(int i = 0; i < a.size(); i++) {
        if(found.find(a[i]) == found.end()){
            found[a[i]] = 1;
        } else {
            duplicateIndex = a[i];
            i = a.size();
        }
    }
    return duplicateIndex;
}

TEST(CodeFights, FirstDuplicate){
    std::map<uint32_t, std::vector<int>> tests {
        {3, {2, 1, 3, 5, 3, 2}}, {-1, {2, 4, 3, 5, 1}}, {-1, {1}},
        {2, {2, 2}}, {-1, {2, 1}}, {-1, {2, 1, 3}}, {3, {2, 3, 3}}, {3, {3, 3, 3}},
        {6, {8, 4, 6, 2, 6, 4, 7, 9, 5, 8}}, {-1, {10, 6, 8, 4, 9, 1, 7, 2, 5, 3}}, {1, {1, 1, 2, 2, 1}}
    };

    for (auto& test: tests) {
        ASSERT_EQ(test.first, CodeFights::first_duplicate(test.second));
    }
}
