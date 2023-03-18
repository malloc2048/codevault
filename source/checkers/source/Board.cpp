#include "Board.h"

#include <vector>
#include <sstream>

const std::string Board::COLUMN_SEPARATOR("|");
const std::string Board::SEPARATOR_STR("\t|-------------------------------|\n");

Board::Board(int x, int y) : boardSizeX(x)
{
    int boardSize = x * y;
    for(int i = 0; i < boardSize; i++) {
        board[i] = Cell();
    }
    initWhite();
    initBlack();
}

#include <iostream>
std::string Board::getBoardString() const
{
    std::vector<std::string> rows;
    std::stringstream ss;

    ss << SEPARATOR_STR;
    for(auto& cell: board) {
        if (cell.first % boardSizeX == 0) {
            ss << cell.first << "\t";
        }
        ss << COLUMN_SEPARATOR << " " << cell.second.getStateStr() << " ";

        if (cell.first % boardSizeX == boardSizeX - 1) {
            ss << COLUMN_SEPARATOR << std::endl;
            ss << SEPARATOR_STR;
        }
    }
    return ss.str();
}

void Board::initWhite()
{
    for(auto& position: whiteCells) {
        auto cell = board.find(position);
        if(cell != board.end())
            cell->second.setState(Cell::WHITE);
    }
}

void Board::initBlack()
{
    for(auto& position: blackCells) {
        auto cell = board.find(position);
        if(cell != board.end())
            cell->second.setState(Cell::BLACK);
    }
}

void Board::processMove(int fromPosition, int toPosition)
{
    const auto positionDiff = abs(fromPosition - toPosition);
    if(positionDiff == (boardSizeX - 1) || positionDiff == (boardSizeX + 1)){
        move(fromPosition, toPosition);
    }
}

void Board::processJump(int fromPosition, int toPosition)
{
    const auto positionDiff = fromPosition - toPosition;
    if(abs(positionDiff) == ((boardSizeX - 1) * 2) || abs(positionDiff) == ((boardSizeX + 1) * 2)) {
        auto cellToClear = board.find(toPosition + (positionDiff / 2));
        if(board.end() != cellToClear){
            cellToClear->second.setState(Cell::EMPTY);
        }
        move(fromPosition, toPosition);
    }
}

Cell::STATE Board::checkForWinner() const
{
    int whiteCount = 0;
    int blackCount = 0;
    for(auto& cell: board){
        if(Cell::WHITE == cell.second.getState()){
            whiteCount++;
        }
        else if(Cell::BLACK == cell.second.getState()) {
            blackCount++;
        }
    }

    if(0 == whiteCount){
        return  Cell::BLACK;
    }
    if(0 == blackCount){
        return Cell::WHITE;
    }
    return Cell::EMPTY;
}

void Board::move(int fromPosition, int toPosition)
{
    auto fromCell = board.find(fromPosition);
    auto toCell = board.find(toPosition);
    if (board.end() != fromCell && board.end() != toCell) {
        toCell->second.setState(fromCell->second.getState());
        fromCell->second.setState(Cell::EMPTY);
    }
}

std::pair<int, int> Board::findMove(Cell::STATE state)
{
    for(auto& cell: board){
        if(Cell::BLACK == state && cell.second.getState() == state){
            if(isValidMove(cell.first, cell.first - 7)){
                return std::make_pair(cell.first, cell.first - 7);
            }
            if(isValidMove(cell.first, cell.first - 9)){
                return std::make_pair(cell.first, cell.first - 9);
            }
        }
        else if(Cell::WHITE == state && cell.second.getState() == state){
            if(isValidMove(cell.first, cell.first + 7)){
                return std::make_pair(cell.first, cell.first + 7);
            }
            if(isValidMove(cell.first, cell.first + 9)){
                return std::make_pair(cell.first, cell.first + 9);
            }
        }
    }
    return std::make_pair(-1, -1);
}

std::pair<int, int> Board::findJump(Cell::STATE state)
{
    for(auto& cell: board){
        if(Cell::BLACK == state && cell.second.getState() == state){
            if(isValidJump_Black(cell.first, cell.first - 7, cell.first - 14)){
                return std::make_pair(cell.first, cell.first - 14);
            }
            if(isValidJump_Black(cell.first, cell.first - 9, cell.first - 18)){
                return std::make_pair(cell.first, cell.first - 18);
            }
        }
        else if(Cell::WHITE == state && cell.second.getState() == state){
            if(isValidJump_White(cell.first, cell.first + 7, cell.first + 14)){
                return std::make_pair(cell.first, cell.first + 14);
            }
            if(isValidJump_White(cell.first, cell.first + 9, cell.first + 18)){
                return std::make_pair(cell.first, cell.first + 18);
            }
        }
    }
    return std::make_pair(-1, -1);
}

bool Board::checkStalemate(Cell::STATE state)
{
    auto jump = findJump(state);
    auto move = findMove(state);
    return jump.first == -1 && jump.second == -1 && move.first == -1 && move.second == -1;
}

std::array<int, 2> Board::performNextAction(Cell::STATE state)
{
    std::array<int, 2> reply{-1, -1};
    auto jump = findJump(state);
    auto move = findMove(state);

    if (jump.first != -1 && jump.second != -1) {
        processJump(jump.first, jump.second);
        reply = {jump.first, jump.second};
    }
    else if(move.first != -1 && move.second != -1){
        processMove(move.first, move.second);
        reply = {move.first, move.second};
    }
    return reply;
}

bool Board::isValidJump_Black(int position, int jumpedPosition, int jumpToPosition)
{
    auto jumpedCell = board.find(jumpedPosition);
    auto jumpTOCell = board.find(jumpToPosition);

    if(jumpedCell != board.end() && jumpTOCell != board.end()){
        int jumpedPositionRowDiff = abs(position - jumpedPosition) % boardSizeX;
        int jumpToPositionRowDiff = abs(position - jumpToPosition) % boardSizeX;
        bool cellsAreValidForJump = jumpedCell->second.getState() == Cell::WHITE &&
            jumpTOCell->second.getState() == Cell::EMPTY;
        return jumpedPositionRowDiff == 1 && jumpToPositionRowDiff == 2 && cellsAreValidForJump;
    }
    return false;
}

bool Board::isValidJump_White(int position, int jumpedPosition, int jumpToPosition)
{
    auto jumpedCell = board.find(jumpedPosition);
    auto jumpTOCell = board.find(jumpToPosition);

    if(jumpedCell != board.end() && jumpTOCell != board.end()){
        int jumpedPositionRowDiff = (position % boardSizeX) - (jumpedPosition % boardSizeX);
        int jumpToPositionRowDiff = (position % boardSizeX) - (jumpToPosition % boardSizeX);
        bool cellsAreValidForJump = jumpedCell->second.getState() == Cell::BLACK &&
                                    jumpTOCell->second.getState() == Cell::EMPTY;
        return abs(jumpedPositionRowDiff) == 1 && abs(jumpToPositionRowDiff) == 2 && cellsAreValidForJump;
    }
    return false;
}

bool Board::isValidMove(int position, int moveToPosition)
{
    auto moveToCell = board.find(moveToPosition);
    if(moveToCell != board.end()){
        int moveToPositionRowDiff = (position % boardSizeX) - (moveToPosition % boardSizeX);
        return abs(moveToPositionRowDiff) == 1 && moveToCell->second.getState() == Cell::EMPTY;
    }
    return false;
}
