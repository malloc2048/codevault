#ifndef HOUSENET_AMAZON_H
#define HOUSENET_AMAZON_H

#include <map>
#include <string>
#include <vector>

class Amazon
{
public:
    Amazon() = default;
    virtual ~Amazon() = default;

    virtual std::vector<std::string> getDirectFriendsForUser(std::string user) = 0;
    virtual std::vector<std::string> getAttendedCoursesForUser(std::string user) = 0;

    std::vector<std::string> getRankedCourses(std::string user);

protected:
    void countFriendCourses(const std::string& user, std::map<std::string, int>& courses);
    void makeCourseCountMap(const std::string& user, std::map<std::string, int>& courses);
    static bool sortFunction(std::pair<std::string, int> first, std::pair<std::string, int> second);
    void rankCourses(std::vector<std::string>& rankedCourses, std::map<std::string, int>& courses);
};
#endif
