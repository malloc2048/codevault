#include "sudoku.h"

int main() {
    // TODO: add being able to get the initial board layout from command line and a file
    const std::map<uint32_t, uint32_t> initial_values {
        {0, 9}, {3, 5}, {7, 8},
        {10, 8}, {11, 7}, {13, 3}, {14, 1}, {15, 4}, {16, 5},
        {21, 4}, {23, 8}, {26, 7},

        {30, 6}, {31, 1}, {32, 9},
        {36, 1}, {44, 3},
        {48, 2}, {49, 8}, {50, 3},

        {54, 5}, {57, 1}, {59, 7},
        {64, 1}, {65, 6}, {66, 8}, {67, 5}, {69, 7}, {70, 3},
        {73, 9}, {77, 6}, {80, 8}
    };

    Sudoku board;
    board.load_board(initial_values);
    board.initialize_empty_cells();

    std::cout << "Initial Board:" << std::endl;
    board.display();

    board.solve();

    std::cout << std::endl << "End Board:" << std::endl;
    board.display();
    return 0;
}
