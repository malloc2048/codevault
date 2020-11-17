#include "amazon.h"
#include <gtest/gtest.h>

int Amazon::find_largest_adjacent_group(std::vector<std::vector<int>> &array) {
    int largest_adjacent_group = 0;
    for(size_t x = 0; x < array.size(); x++) {
        for(size_t y = 0; y < array[x].size(); y++) {
            if(array[x][y] == 1) {
                auto temp = count_adjacent(array, x, y);
                largest_adjacent_group = largest_adjacent_group < temp ? temp : largest_adjacent_group;
            }
        }
    }
    return largest_adjacent_group;
}

int Amazon::count_adjacent(std::vector<std::vector<int>> &array, size_t x, size_t y) {
    if(x < 0 or x >= array.size())
        return 0;
    if(y < 0 or y >= array[x].size())
        return 0;

    int count = 0;
    if(array[x][y] == 1) {
        array[x][y] = 0;
        count++;

        count += count_adjacent(array, x - 1, y);
        count += count_adjacent(array, x + 1, y);
        count += count_adjacent(array, x, y - 1);
        count += count_adjacent(array, x, y + 1);
    }
    return count;
}

TEST(Amazon, LargestAdjacentGroup) {
    std::vector<std::vector<int>> array = {
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 1}
    };

    ASSERT_EQ(4, Amazon::find_largest_adjacent_group(array));
}
