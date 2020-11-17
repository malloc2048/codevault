#include "amazon.h"
#include <algorithm>
#include <gtest/gtest.h>

int Amazon::find_smallest_gap_distance(std::vector<int> &array) {
    if(array.empty()) {
        return -1;
    }

    auto gap_distance = INT_MAX;
    std::sort(array.begin(), array.end());

    for(size_t i = 0; i < array.size() - 1; i++){
        auto temp = array[i + 1] - array[i];
        if(temp < gap_distance) {
            gap_distance = temp;
        }
    }
    return gap_distance;
}

TEST(AmazonTest, GapDistance) {
    std::vector<int> arrayNoGap = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(1, Amazon::find_smallest_gap_distance(arrayNoGap));

    std::vector<int> arrayWithGap = {4, 8};
    ASSERT_EQ(4, Amazon::find_smallest_gap_distance(arrayWithGap));

    std::vector<int> arrayWithMultipleGaps = {1, 5, 9, 100};
    ASSERT_EQ(4, Amazon::find_smallest_gap_distance(arrayWithMultipleGaps));

    std::vector<int> emptyArray = {};
    ASSERT_EQ(-1, Amazon::find_smallest_gap_distance(emptyArray));

    std::vector<int> unsorted = {100, 200, 1, 55, 22, 88};
    ASSERT_EQ(12, Amazon::find_smallest_gap_distance(unsorted));
}
