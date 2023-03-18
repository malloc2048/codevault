#include "sudoku.h"
#include "helpers.h"
#include "gtest/gtest.h"

TEST(Sudoku, execution) {
    TestHelpers::init();
    ASSERT_TRUE(true);

    Sudoku sudoku;
    sudoku.initBoard(TestHelpers::initialValues);

    auto board = sudoku.getBoard();
    TestHelpers::printBoard(board);
}
