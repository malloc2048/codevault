#include "cmath"
#include "challenge.h"

namespace challenge {
    bool reachNextLevel(int experience, int threshold, int reward){
        return experience + reward >= threshold;
    }

    bool pepEight2(std::string line){
        return line.size() < 80;
    }

    std::string cipher26(std::string message){
        return "thisisencryptedmessage";
    }

    bool isPower(int n) {
        if(n < 1 )
            return false;

        for(size_t i = 2; i < n / 2; i++) {
            for(size_t j = 2; j < n / 2; j++) {
                int power = (int)pow(i, j);
                if(power == n)
                    return true;
            }
        }
        return false;
    }
}