// Because there are numerous loops in this example the time complexity would be on the order of n squared.
// specifically number of friends * number of courses each friend has.
/*
 * #include <map>
 * #include <set>
 * #include <list>
 * #include <cmath>
 * #include <ctime>
 * #include <climits>
 * #include <deque>
 * #include <queue>
 * #include <stack>
 * #include <bitset>
 * #include <cstdio>
 * #include <limits>
 * #include <vector>
 * #include <cstdlib>
 * #include <fstream>
 * #include <numeric>
 * #include <sstream>
 * #include <iostream>
 * #include <algorithm>
 * using namespace std;
 *
 * vector<string> getDirectFriendsForUser(string user)
 *
 * vector<string> getAttendedCoursesForUser(string user)
 *
 * Complete the function below.
 */
void debugShowMap( vector<pair<string, int> >& sortedCourses )
{
    vector<pair<string, int> >::iterator itr = sortedCourses.begin();
    for( ; itr != sortedCourses.end(); ++itr )
    {
        std::cout << itr->first << std::endl;
    }
}

void debugShowCourses( map<string, int>& courses )
{
    map<string, int>::iterator itr = courses.begin();
    for( ; itr != courses.end(); ++itr )
    {
        std::cout << itr->first << std::endl;
    } 
}

void countFriendCourses( string friendName, map<string, int>& mapOfAttendedCourses, bool goToNextLevel = true )
{
    vector<string> courses = getAttendedCoursesForUser( friendName );
    vector<string>::iterator courseItr = courses.begin();
    for( ; courseItr != courses.end(); ++courseItr )
    {
        //std::cout << friendName << ":" << *courseItr << std::endl;
        mapOfAttendedCourses[*courseItr]++;
    }
}

void removeUserCourses( string user, map<string, int>& mapOfAttendedCourses )
{
    //debugShowCourses( mapOfAttendedCourses );
    vector<string> usersCourses = getAttendedCoursesForUser( user );
    vector<string>::iterator itr = usersCourses.begin();
    for( ; itr != usersCourses.end(); ++itr )
    {
        if( mapOfAttendedCourses.find( *itr ) != mapOfAttendedCourses.end() )
        {
            // This user course was found
            mapOfAttendedCourses[*itr] = 0;
        }
    }    
}

void populateRankedCourses(vector<pair<string, int> >& sortedCourses, vector<string>& rankedCourseRecommendations )
{
    vector<pair<string, int> >::iterator itr = sortedCourses.begin();
    for( ; itr != sortedCourses.end(); ++itr )
    {
        if( itr->second > 0 )
            rankedCourseRecommendations.push_back( itr->first );
    }
}

bool sortFunction( pair<string, int> first, pair<string, int> second)
{
    if( first.second > second.second )
        return true;
    return false;
}

vector<string> getRankedCourses(string user) {
    vector<string> rankedCourseRecommendations;
    map<string, int> mapOfAttendedCourses;

    vector<string> usersDirectFriends = getDirectFriendsForUser( user );
    vector<string>::iterator itr = usersDirectFriends.begin();
    
    for( ; itr != usersDirectFriends.end(); ++itr )
    {
        //std::cout << *itr << std::endl;
        countFriendCourses( *itr, mapOfAttendedCourses );
        
        vector<string> usersSocialDirectFriends = getDirectFriendsForUser( *itr );
        vector<string>::iterator itrSocial = usersSocialDirectFriends.begin();
        for( ; itrSocial != usersSocialDirectFriends.end(); ++itrSocial )
        {
            countFriendCourses( *itrSocial, mapOfAttendedCourses );
        }
    }

    removeUserCourses( user, mapOfAttendedCourses );
    
    vector<pair<string, int> > courseRecommendations( mapOfAttendedCourses.begin(), mapOfAttendedCourses.end());
    sort( courseRecommendations.begin(), courseRecommendations.end(), &sortFunction );
    populateRankedCourses( courseRecommendations, rankedCourseRecommendations );
    
    return rankedCourseRecommendations;
}

















/*
 * #include <map>
 * #include <set>
 * #include <list>
 * #include <cmath>
 * #include <ctime>
 * #include <climits>
 * #include <deque>
 * #include <queue>
 * #include <stack>
 * #include <bitset>
 * #include <cstdio>
 * #include <limits>
 * #include <vector>
 * #include <cstdlib>
 * #include <fstream>
 * #include <numeric>
 * #include <sstream>
 * #include <iostream>
 * #include <algorithm>
 * using namespace std;
 *
 * vector<string> getDirectFriendsForUser(string user)
 *
 * vector<string> getAttendedCoursesForUser(string user)
 *
 * Complete the function below.
 */
void countFriendCourses( string friendName, map<string, int>& mapOfAttendedCourses, bool goToNextLevel = true )
{
    vector<string> courses = getAttendedCoursesForUser( friendName );
    vector<string>::iterator courseItr = courses.begin();
    for( ; courseItr != courses.end(); ++courseItr )
    {
        mapOfAttendedCourses[*courseItr]++;
    }
}

void removeUserCourses( string user, map<string, int>& mapOfAttendedCourses )
{
    vector<string> usersCourses = getAttendedCoursesForUser( user );
    vector<string>::iterator itr = usersCourses.begin();
    for( ; itr != usersCourses.end(); ++itr )
    {
        if( mapOfAttendedCourses.find( *itr ) != mapOfAttendedCourses.end() )
        {
            // This user course was found
            mapOfAttendedCourses[*itr] = 0;
        }
    }    
}

void populateRankedCourses(vector<pair<string, int> >& sortedCourses, vector<string>& rankedCourseRecommendations )
{
    vector<pair<string, int> >::iterator itr = sortedCourses.begin();
    for( ; itr != sortedCourses.end(); ++itr )
    {
        if( itr->second > 0 )
            rankedCourseRecommendations.push_back( itr->first );
    }
}

bool sortFunction( pair<string, int> first, pair<string, int> second)
{
    if( first.second > second.second )
        return true;
    return false;
}

 void countAllCourses( string user, map<string, int>& mapOfAttendedCourses )
 {
    vector<string> usersDirectFriends = getDirectFriendsForUser( user );
    vector<string>::iterator itr = usersDirectFriends.begin();
    
    for( ; itr != usersDirectFriends.end(); ++itr )
    {
        countFriendCourses( *itr, mapOfAttendedCourses );
        
        vector<string> usersSocialDirectFriends = getDirectFriendsForUser( *itr );
        vector<string>::iterator itrSocial = usersSocialDirectFriends.begin();
        for( ; itrSocial != usersSocialDirectFriends.end(); ++itrSocial )
        {
            countFriendCourses( *itrSocial, mapOfAttendedCourses );
        }
    }  
 }

vector<string> getRankedCourses(string user) {
    vector<string> rankedCourseRecommendations;
    map<string, int> mapOfAttendedCourses;

    countAllCourses( user, mapOfAttendedCourses );
    removeUserCourses( user, mapOfAttendedCourses );
    
    vector<pair<string, int> > courseRecommendations( mapOfAttendedCourses.begin(), mapOfAttendedCourses.end());
    sort( courseRecommendations.begin(), courseRecommendations.end(), &sortFunction );
    populateRankedCourses( courseRecommendations, rankedCourseRecommendations );
    
    return rankedCourseRecommendations;
}