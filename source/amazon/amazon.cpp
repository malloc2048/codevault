#include "amazon.h"

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

std::vector<std::string> Amazon::getRankedCourses(std::string user)
{
    std::map<std::string, int> mapOfAttendedCourses;

    std::vector<std::string> friends = getDirectFriendsForUser(user);
    std::set<std::string> friendSet(friends.begin(), friends.end());

    makeCourseCountMap(user, mapOfAttendedCourses);

    for(auto& directFriend: friends)
    {
        std::vector<std::string> indirectFriends = getDirectFriendsForUser(directFriend);
        friendSet.insert(indirectFriends.begin(), indirectFriends.end());
    }

    for(auto& friendInSet: friendSet)
    {
        countFriendCourses(friendInSet, mapOfAttendedCourses);
    }

    std::vector<std::string> rankedCourseRecommendations;
    rankCourses(rankedCourseRecommendations, mapOfAttendedCourses);
    return rankedCourseRecommendations;
}

void Amazon::makeCourseCountMap(const std::string& user, std::map<std::string, int> &courses)
{
    std::vector<std::string> courseList = getAttendedCoursesForUser(user);
    for(auto& course: courseList)
    {
        courses[course] = 0;
    }
}

void Amazon::countFriendCourses(const std::string &user, std::map<std::string, int>& courses)
{
    std::vector<std::string> courseList = getAttendedCoursesForUser(user);
    for(auto& course: courseList)
    {
        if(courses.end() == courses.find(course))
        {
            courses[course] += 1;
        }
        else if(courses[course] > 0)
        {
            courses[course] += 1;
        }
    }
}

void Amazon::rankCourses(std::vector<std::string>& rankedCourses, std::map<std::string, int>& courses)
{
    std::vector<std::pair<std::string, int> > courseRecommendations( courses.begin(), courses.end());
    std::sort( courseRecommendations.begin(), courseRecommendations.end(), &Amazon::sortFunction);
    for(auto& course: courseRecommendations)
    {
        if(course.second > 0)
            rankedCourses.emplace_back(course.first);
    }
}

bool Amazon::sortFunction(std::pair<std::string, int> first, std::pair<std::string, int> second)
{
    return first.second > second.second;
}
