#include "level1.h"

namespace level1 {
    int add(int param1, int param2) {
        return param1 + param2;
    }

    int centuryFromYear(int year) {
        if(year % 100 == 0){
            return year / 100;
        }
        else{
            return (year / 100) + 1;
        }
    }

    bool checkPalindrome(std::string inputString) {
        for(size_t front = 0, back = inputString.size() - 1; back > front; front++, back--){
            if(inputString[front] != inputString[back]){
                return false;
            }
        }
        return true;
    }



}
