#ifndef PORTFOLIO_CODE_FIGHTS_H
#define PORTFOLIO_CODE_FIGHTS_H

#include <string>
#include <vector>

namespace CodeFights {
    struct Visited{
        int col;
        int row;
    };

    bool is_power(int n);
    bool pep_eight(std::string line);
    int first_duplicate(std::vector<int> a);
    bool bored_friends(const std::string& n);
    std::string cipher26(const std::string& message);
    char first_not_repeating_character(const std::string& s);
    bool reach_next_level(int experience, int threshold, int reward);
    std::vector<int> least_appearance(std::vector<std::vector<int>> choices);
    std::vector<std::vector<int>> rotate_image(std::vector<std::vector<int>> a);
};
#endif
