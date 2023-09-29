#ifndef CODEVAULT_INTRO_H
#define CODEVAULT_INTRO_H

#include <string>
#include <vector>

class Intro {
public:
    Intro() = default;
    ~Intro() = default;

    struct Level1 {
        static int add(int param1, int param2);
        static int century_from_year(int year);
        static bool check_palindrome(std::string inputString);
    };

    struct Level2 {
        static int adjacentElementsProduct(std::vector<int> inputArray);
        static int shapeArea(int n);
        static int makeArrayConsecutive2(std::vector<int> statues);
        static bool almostIncreasingSequence(std::vector<int> sequence);
        static int matrixElementsSum(std::vector<std::vector<int>> matrix);
    };

    struct Level3 {
        static std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray);
        static int commonCharacterCount(std::string s1, std::string s2) ;
    };

protected:
private:
};
#endif
