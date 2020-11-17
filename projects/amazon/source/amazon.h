#ifndef PORTFOLIO_AMAZON_H
#define PORTFOLIO_AMAZON_H

#include <map>
#include <string>
#include <vector>

namespace Amazon {
    std::vector<std::string> get_ranked_courses(std::string& user);
    std::vector<std::string> get_direct_friends_for_user(const std::string& user);
    std::vector<std::string> get_attended_courses_for_user(const std::string& user);

    void count_friend_courses(const std::string& user, std::map<std::string, int>& courses);
    void make_course_count_map(const std::string& user, std::map<std::string, int>& courses);
    bool sort_function(std::pair<std::string, int>& first, std::pair<std::string, int>& second);
    void rank_courses(std::vector<std::string>& ranked_courses, std::map<std::string, int>& courses);

    int find_largest_adjacent_group(std::vector<std::vector<int>> &array);
    int count_adjacent(std::vector<std::vector<int>> &array, size_t x, size_t y);

    int find_smallest_gap_distance(std::vector<int> &array);

    int find_largest_turbulence_period(std::vector<int>& array);
    int count_turbulence_positive(std::vector<int>& array, size_t position);
    int count_turbulence_negative(std::vector<int>& array, size_t position);
};
#endif
