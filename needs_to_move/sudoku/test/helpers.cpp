#include "helpers.h"

namespace TestHelpers {
    void init() {
        initialValues = {
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 1), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 2), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 3), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 4), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 5), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 6), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 7), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(0, 8), 9),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 0), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 1), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 2), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 3), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 4), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 5), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 6), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 7), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(1, 8), 3),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 0), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 1), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 2), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 3), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 4), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 5), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 6), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 7), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(2, 8), 6),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 0), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 1), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 2), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 3), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 4), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 5), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 6), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 7), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(3, 8), 7),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 0), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 1), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 2), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 3), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 4), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 5), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 6), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 7), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(4, 8), 4),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 0), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 1), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 2), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 3), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 4), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 5), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 6), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 7), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(5, 8), 5),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 0), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 1), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 2), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 3), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 4), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 5), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 6), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 7), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(6, 8), 8),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 0), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 1), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 2), 2),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 3), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 4), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 5), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 6), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 7), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(7, 8), 1),

            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 0), 9),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 1), 7),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 2), 8),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 3), 5),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 4), 3),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 5), 1),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 6), 6),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 7), 4),
            std::pair<std::pair<int, int>, int>(std::pair<int, int>(8, 8), 2)
        };
    }

    void printBoard(std::vector<std::vector<int>>& board) {
        std::cout << std::endl << "=======================================" << std::endl;
        for(size_t i = 0; i < board.size(); i++) {
            std::cout << "|";
            for(auto col: board[i]) {
                std::cout << "| " << col << " ";
            }
            std::cout << "||" << std::endl;

            if(i < board.size() - 1){
                std::cout << "---------------------------------------" << std::endl;
            }
        }
        std::cout << "=======================================" << std::endl;
    }
}