#include <set>
#include "amazon.h"
#include <algorithm>

std::vector<std::string> Amazon::get_ranked_courses(std::string& user) {
    std::map<std::string, int> map_attended_courses;
    std::vector<std::string> friends = get_direct_friends_for_user(user);
    std::set<std::string> friend_set(friends.begin(), friends.end());

    make_course_count_map(user, map_attended_courses);

    for(auto& directFriend: friends) {
        std::vector<std::string> indirectFriends = get_direct_friends_for_user(directFriend);
        friend_set.insert(indirectFriends.begin(), indirectFriends.end());
    }

    for(auto& friendInSet: friend_set) {
        count_friend_courses(friendInSet, map_attended_courses);
    }

    std::vector<std::string> ranked_course_recommendations;
    rank_courses(ranked_course_recommendations, map_attended_courses);
    return ranked_course_recommendations;
}

std::vector<std::string> Amazon::get_direct_friends_for_user(const std::string& user) {
    return std::vector<std::string>();
}

std::vector<std::string> Amazon::get_attended_courses_for_user(const std::string& user) {
    return std::vector<std::string>();
}

void Amazon::count_friend_courses(const std::string& user, std::map<std::string, int>& courses) {
    std::vector<std::string> course_list = get_attended_courses_for_user(user);
    for(auto& course: course_list) {
        // TODO: does a search need to be done first to see if the course exists?
        courses[course] += 1;
    }
}

void Amazon::make_course_count_map(const std::string& user, std::map<std::string, int>& courses) {
    std::vector<std::string> courseList = get_attended_courses_for_user(user);
    for(auto& course: courseList) {
        courses[course] = 0;
    }
}

bool Amazon::sort_function(std::pair<std::string, int>& first, std::pair<std::string, int>& second) {
    return first.second > second.second;
}

void Amazon::rank_courses(std::vector<std::string>& ranked_courses, std::map<std::string, int>& courses) {
    std::vector<std::pair<std::string, int> > course_recommendations( courses.begin(), courses.end());
    std::sort( course_recommendations.begin(), course_recommendations.end(), &Amazon::sort_function);
    for(auto& course: course_recommendations) {
        if(course.second > 0)
            ranked_courses.emplace_back(course.first);
    }
}
