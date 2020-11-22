#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H

#include <map>
#include <list>
#include <string>
#include "bell.h"

class Board
{
public:
    explicit Board(int x = 8, int y = 8);
    ~Board() = default;

    std::string get_board_string() const;
    Cell::STATE check_for_winner() const;
    void process_move(int from_position, int to_position);
    void process_jump(int from_position, int to_position);

    std::pair<int, int> find_move(Cell::STATE state);
    std::pair<int, int> find_jump(Cell::STATE state);

    bool check_stalemate(Cell::STATE state);
    std::array<int, 2> perform_next_action(Cell::STATE state);

protected:
    void init_white();
    void init_black();

    void move(int fromPosition, int toPosition);

    bool is_valid_jump_black(int position, int jumped_position, int jump_to_position);
    bool is_valid_jump_white(int position, int jumped_position, int jump_to_position);

    bool is_valid_move(int position, int move_to_position);

private:
    int board_size_x;

    std::array<int, 12> white_cells = {{1, 3, 5, 7, 8, 10, 12, 14, 17, 19, 21, 23}};
    std::array<int, 12> black_cells = {{40, 42, 44, 46, 49, 51, 53, 55, 56, 58, 60, 62}};
    std::map<int, Cell> board;

    static const std::string SEPARATOR_STR;
    static const std::string COLUMN_SEPARATOR;
};
#endif
