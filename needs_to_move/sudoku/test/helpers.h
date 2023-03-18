#ifndef CODESIGNAL_HELPERS_H
#define CODESIGNAL_HELPERS_H

#include <vector>
#include <iostream>

namespace TestHelpers {
    static std::vector<std::pair<std::pair<int, int>, int>> initialValues;

    void init();
    void printBoard(std::vector<std::vector<int>>& board);
}
#endif
