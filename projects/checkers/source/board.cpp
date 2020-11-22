#include "board.h"

#include <vector>
#include <sstream>

const std::string Board::COLUMN_SEPARATOR("|");
const std::string Board::SEPARATOR_STR("\t|-------------------------------|\n");

Board::Board(int x, int y) : board_size_x(x)
{
    int boardSize = x * y;
    for(int i = 0; i < boardSize; i++) {
        board[i] = Cell();
    }
    init_white();
    init_black();
}

#include <iostream>
std::string Board::get_board_string() const
{
    std::vector<std::string> rows;
    std::stringstream ss;

    ss << SEPARATOR_STR;
    for(auto& cell: board) {
        if (cell.first % board_size_x == 0) {
            ss << cell.first << "\t";
        }
        ss << COLUMN_SEPARATOR << " " << cell.second.getStateStr() << " ";

        if (cell.first % board_size_x == board_size_x - 1) {
            ss << COLUMN_SEPARATOR << std::endl;
            ss << SEPARATOR_STR;
        }
    }
    return ss.str();
}

void Board::init_white()
{
    for(auto& position: white_cells) {
        auto cell = board.find(position);
        if(cell != board.end())
            cell->second.setState(Cell::WHITE);
    }
}

void Board::init_black()
{
    for(auto& position: black_cells) {
        auto cell = board.find(position);
        if(cell != board.end())
            cell->second.setState(Cell::BLACK);
    }
}

void Board::process_move(int from_position, int to_position)
{
    const auto positionDiff = abs(from_position - to_position);
    if(positionDiff == (board_size_x - 1) || positionDiff == (board_size_x + 1)){
        move(from_position, to_position);
    }
}

void Board::process_jump(int from_position, int to_position)
{
    const auto positionDiff = from_position - to_position;
    if(abs(positionDiff) == ((board_size_x - 1) * 2) || abs(positionDiff) == ((board_size_x + 1) * 2)) {
        auto cellToClear = board.find(to_position + (positionDiff / 2));
        if(board.end() != cellToClear){
            cellToClear->second.setState(Cell::EMPTY);
        }
        move(from_position, to_position);
    }
}

Cell::STATE Board::check_for_winner() const
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

std::pair<int, int> Board::find_move(Cell::STATE state)
{
    for(auto& cell: board){
        if(Cell::BLACK == state && cell.second.getState() == state){
            if(is_valid_move(cell.first, cell.first - 7)){
                return std::make_pair(cell.first, cell.first - 7);
            }
            if(is_valid_move(cell.first, cell.first - 9)){
                return std::make_pair(cell.first, cell.first - 9);
            }
        }
        else if(Cell::WHITE == state && cell.second.getState() == state){
            if(is_valid_move(cell.first, cell.first + 7)){
                return std::make_pair(cell.first, cell.first + 7);
            }
            if(is_valid_move(cell.first, cell.first + 9)){
                return std::make_pair(cell.first, cell.first + 9);
            }
        }
    }
    return std::make_pair(-1, -1);
}

std::pair<int, int> Board::find_jump(Cell::STATE state)
{
    for(auto& cell: board){
        if(Cell::BLACK == state && cell.second.getState() == state){
            if(is_valid_jump_black(cell.first, cell.first - 7, cell.first - 14)){
                return std::make_pair(cell.first, cell.first - 14);
            }
            if(is_valid_jump_black(cell.first, cell.first - 9, cell.first - 18)){
                return std::make_pair(cell.first, cell.first - 18);
            }
        }
        else if(Cell::WHITE == state && cell.second.getState() == state){
            if(is_valid_jump_white(cell.first, cell.first + 7, cell.first + 14)){
                return std::make_pair(cell.first, cell.first + 14);
            }
            if(is_valid_jump_white(cell.first, cell.first + 9, cell.first + 18)){
                return std::make_pair(cell.first, cell.first + 18);
            }
        }
    }
    return std::make_pair(-1, -1);
}

bool Board::check_stalemate(Cell::STATE state)
{
    auto jump = find_jump(state);
    auto move = find_move(state);
    return jump.first == -1 && jump.second == -1 && move.first == -1 && move.second == -1;
}

std::array<int, 2> Board::perform_next_action(Cell::STATE state)
{
    std::array<int, 2> reply{-1, -1};
    auto jump = find_jump(state);
    auto move = find_move(state);

    if (jump.first != -1 && jump.second != -1) {
        process_jump(jump.first, jump.second);
        reply = {jump.first, jump.second};
    }
    else if(move.first != -1 && move.second != -1){
        process_move(move.first, move.second);
        reply = {move.first, move.second};
    }
    return reply;
}

bool Board::is_valid_jump_black(int position, int jumped_position, int jump_to_position)
{
    auto jumpedCell = board.find(jumped_position);
    auto jumpTOCell = board.find(jump_to_position);

    if(jumpedCell != board.end() && jumpTOCell != board.end()){
        int jumpedPositionRowDiff = abs(position - jumped_position) % board_size_x;
        int jumpToPositionRowDiff = abs(position - jump_to_position) % board_size_x;
        bool cellsAreValidForJump = jumpedCell->second.getState() == Cell::WHITE &&
            jumpTOCell->second.getState() == Cell::EMPTY;
        return jumpedPositionRowDiff == 1 && jumpToPositionRowDiff == 2 && cellsAreValidForJump;
    }
    return false;
}

bool Board::is_valid_jump_white(int position, int jumped_position, int jump_to_position)
{
    auto jumpedCell = board.find(jumped_position);
    auto jumpTOCell = board.find(jump_to_position);

    if(jumpedCell != board.end() && jumpTOCell != board.end()){
        int jumpedPositionRowDiff = (position % board_size_x) - (jumped_position % board_size_x);
        int jumpToPositionRowDiff = (position % board_size_x) - (jump_to_position % board_size_x);
        bool cellsAreValidForJump = jumpedCell->second.getState() == Cell::BLACK &&
                                    jumpTOCell->second.getState() == Cell::EMPTY;
        return abs(jumpedPositionRowDiff) == 1 && abs(jumpToPositionRowDiff) == 2 && cellsAreValidForJump;
    }
    return false;
}

bool Board::is_valid_move(int position, int move_to_position)
{
    auto moveToCell = board.find(move_to_position);
    if(moveToCell != board.end()){
        int moveToPositionRowDiff = (position % board_size_x) - (move_to_position % board_size_x);
        return abs(moveToPositionRowDiff) == 1 && moveToCell->second.getState() == Cell::EMPTY;
    }
    return false;
}
