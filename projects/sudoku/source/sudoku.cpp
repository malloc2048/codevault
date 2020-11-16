#include "sudoku.h"

void Sudoku::solve() {
    while (!is_board_complete()) {
        for (auto &row: rows)
            update_cells(row);

        for (auto &column: columns)
            update_cells(column);

        for (auto &block: blocks)
            update_cells(block);
    }
}

void Sudoku::display() {
    for(auto i = 0; i < 81; i++) {
        if ((i % 9) == 0 && i > 0)
            std::cout << std::endl;

        if(board[i].size() == 1)
            std::cout << board[i][0] << "\t";
        else
            std::cout << "*\t";
    }
}

bool Sudoku::is_board_complete() {
    if (std::all_of(board.begin(), board.end(), [](const Cell& cell){ return cell.size() == 1; })) {
        bool calculation_ok = std::all_of(rows.begin(), rows.end(), [this](const std::vector<uint32_t>& block) {
            if (calculate_sum(block) != block_sum)
                return false;
            return true;
        });

        calculation_ok &= std::all_of(columns.begin(), columns.end(), [this](const std::vector<uint32_t>& block) {
            if (calculate_sum(block) != block_sum)
                return false;
            return true;
        });

        calculation_ok &= std::all_of(blocks.begin(), blocks.end(), [this](const std::vector<uint32_t>& block) {
            if (calculate_sum(block) != block_sum)
                return false;
            return true;
        });

        return calculation_ok;
    }
    return false;
}

void Sudoku::initialize_empty_cells() {
    Cell default_cell { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto& cell: board) {
        if (cell.empty()) {
            cell = default_cell;
        }
    }
}

void Sudoku::update_cells(const std::vector<uint32_t>& indexes) {
    std::set<uint32_t> claimed_values;
    std::map<uint32_t, uint32_t> value_counts {
        {1, 0}, {2, 0}, {3, 0}, {4, 0},
        {5, 0}, {6, 0}, {7, 0}, {8, 0},
        {9, 0}
    };

    // for all cells that have a single value, add to the claimed values
    for (auto& index: indexes) {
        if (board[index].size() == 1) {
            claimed_values.insert(board[index][0]);
        }
    }

    // remove values from each cell that has more than one value if it is not available
    for (auto& index: indexes) {
        if (board[index].size() > 1) {
            for (auto value: claimed_values) {
                auto found = std::find(board[index].begin(), board[index].end(), value);
                if (found != board[index].end()) // value found, remove it
                    board[index].erase(found);
            }
        }
    }

    // count the number of occurrences of each number in the block
    for (auto& index: indexes) {
        for (auto& cell_value: board[index]) {
            value_counts[cell_value]++;
        }
    }

    // iterate block cells and if a value in a cell has a count == 1 remove all other values
    for (auto& index: indexes) {
        if (board[index].size() > 1) {
            for (auto& value: board[index]) {
                if (value_counts[value] == 1) {
                    board[index].erase(board[index].begin() + 1, board[index].end());
                    board[index][0] = value;
                    break;
                }
            }
        }
    }
}

void Sudoku::load_board(const std::map<uint32_t, uint32_t> &initial_values) {
    for (auto& value: initial_values) {
        if (value.first < board.size()) {
            board[value.first].emplace_back(value.second);
        }
    }
}

uint32_t Sudoku::calculate_sum(const std::vector<uint32_t> &indexes) {
    auto sum = 0;
    for (auto& index: indexes) {
        for (auto &value: board[index]) {
            sum += value;
        }
    }
    return sum;
}
