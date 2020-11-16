#ifndef PORTFOLIO_CODE_FIGHTS_H
#define PORTFOLIO_CODE_FIGHTS_H

#include <string>
#include <vector>

namespace CodeFights {
    struct Visited{
        int col;
        int row;
    };

    int first_duplicate(std::vector<int> a);
    char first_not_repeating_character(const std::string& s);
    std::vector<std::vector<int>> rotate_image(std::vector<std::vector<int>> a);
};
#endif
