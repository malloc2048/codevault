#include <map>
#include <algorithm>
#include "code_fights.h"
#include <gtest/gtest.h>

bool not_visited(int col, int row, std::vector<std::pair<int, int>>& visited) {
    auto new_pair = std::make_pair(col, row);
    auto visited_pair = std::find(visited.begin(), visited.end(), new_pair);
    return !(visited.end() != visited_pair);
}

std::vector<std::vector<int>> CodeFights::rotate_image(std::vector<std::vector<int>> a) {
    std::vector<std::pair<int, int>> visited;

    for (int col = 0; col < a.size(); col++){
        for (int row = 0; row < a[col].size(); row++){
            if (not_visited(col, row, visited)) {
                auto newPosition = static_cast<int>(a[row].size() - 1 - col);
                visited.emplace_back(row, newPosition);
                int temp = a[col][row];
                a[col][row] = a[row][a[row].size() - 1 - col];
                a[row][a[row].size() - 1 - col] = temp;
            }
        }
    }
    return a;
}

TEST(CodeFights, RotateImage) {
    std::vector<int> expectedRow1 = {7, 4, 1};
    std::vector<int> expectedRow2 = {8, 5, 2};
    std::vector<int> expectedRow3 = {9, 6, 3};
    std::vector<std::vector<int>> expectedArray = {expectedRow1, expectedRow2, expectedRow3};

    std::vector<int> row1 = {1, 2, 3};
    std::vector<int> row2 = {4, 5, 6};
    std::vector<int> row3 = {7, 8, 9};
    std::vector<std::vector<int>> array = {row1, row2, row3};

    ASSERT_EQ(expectedArray, CodeFights::rotate_image(array));
}
