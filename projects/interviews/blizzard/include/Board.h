#ifndef BLIZZARD_BOARD_H
#define BLIZZARD_BOARD_H

#include <map>
#include <list>
#include <string>
#include "Cell.h"

class Board
{
public:
    explicit Board(int x = 8, int y = 8);
    ~Board() = default;

    std::string getBoardString() const;
    Cell::STATE checkForWinner() const;
    void processMove(int fromPosition, int toPosition);
    void processJump(int fromPosition, int toPosition);

    std::pair<int, int> findMove(Cell::STATE state);
    std::pair<int, int> findJump(Cell::STATE state);

    bool checkStalemate(Cell::STATE state);
    std::array<int, 2> performNextAction(Cell::STATE state);

protected:
    void initWhite();
    void initBlack();

    void move(int fromPosition, int toPosition);

    bool isValidJump_Black(int position, int jumpedPosition, int jumpToPosition);
    bool isValidJump_White(int position, int jumpedPosition, int jumpToPosition);

    bool isValidMove(int position, int moveToPosition);

private:
    int boardSizeX;

    std::array<int, 12> whiteCells = {{1, 3, 5, 7, 8, 10, 12, 14, 17, 19, 21, 23}};
    std::array<int, 12> blackCells = {{40, 42, 44, 46, 49, 51, 53, 55, 56, 58, 60, 62}};
    std::map<int, Cell> board;

    static const std::string SEPARATOR_STR;
    static const std::string COLUMN_SEPARATOR;
};
#endif
