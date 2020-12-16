#include <bits/stdc++.h>
#include <algorithm>
#include "gapdistance.h"

int GapDistance::findSmallestGapDistance(std::vector<int> &array) {
    if(array.empty()) {
        return -1;
    }

    gapDistance = INT_MAX;
    std::sort(array.begin(), array.end());

    for(size_t i = 0; i < array.size() - 1; i++){
        auto temp = array[i + 1] - array[i];
        if(temp < gapDistance) {
            gapDistance = temp;
        }
    }
    return gapDistance;
}
