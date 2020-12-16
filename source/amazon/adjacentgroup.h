#ifndef CODESIGNAL_ADJACENTGROUP_H
#define CODESIGNAL_ADJACENTGROUP_H

#include <vector>
#include <cstdlib>

namespace AmazonProblems {
    class AdjacentGroup {
    public:
        AdjacentGroup() = default;
        ~AdjacentGroup() = default;

        int findLargestAdjacentGroup(std::vector<std::vector<int>> &array);

    private:
        int countAdjacent(std::vector<std::vector<int>> &array, size_t x, size_t y);
    };
};
#endif
