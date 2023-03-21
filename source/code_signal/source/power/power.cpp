#include <cmath>
#include "power.h"

bool Power::is_power(int n) {
    if(n < 1 )
        return false;

    for(auto i = 2; i < n / 2; i++) {
        for(auto j = 2; j < n / 2; j++) {
            auto power = pow(i, j);
            if(power == n)
                return true;
        }
    }
    return false;
}
