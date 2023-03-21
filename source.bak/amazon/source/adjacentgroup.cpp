#include "adjacentgroup.h"

int AmazonProblems::AdjacentGroup::findLargestAdjacentGroup(std::vector<std::vector<int>> &array) {
    int largestAdjacentGroup = 0;
    for(size_t x = 0; x < array.size(); x++) {
        for(size_t y = 0; y < array[x].size(); y++) {
            if(array[x][y] == 1) {
                auto temp = countAdjacent(array, x, y);
                largestAdjacentGroup = largestAdjacentGroup < temp ? temp : largestAdjacentGroup;
            }
        }
    }
    return largestAdjacentGroup;
}

int AmazonProblems::AdjacentGroup::countAdjacent(std::vector<std::vector<int>> &array, size_t x, size_t y) {
    if(x < 0 or x >= array.size())
        return 0;
    if(y < 0 or y >= array[x].size())
        return 0;

    int count = 0;
    if(array[x][y] == 1) {
        array[x][y] = 0;
        count++;

        count += countAdjacent(array, x - 1, y);
        count += countAdjacent(array, x + 1, y);
        count += countAdjacent(array, x, y - 1);
        count += countAdjacent(array, x, y + 1);
    }
    return count;
}
