#include "turbulence.h"
#include <iostream>

int Turbulence::findLargestTurbulencePeriod(std::vector<int> &array) {
    if(array.size() <= 1) {
        return 0;
    }

    size_t i = 0;
    int turbulence = 0;

    while(i < array.size() - 1) {
        if(array[i] < array[i + 1]) {
            auto turbulenceLength = countTurbulencePositive(array, i);
            i += turbulenceLength;
            turbulence = turbulence < turbulenceLength ? turbulenceLength : turbulence;
        } else if(array[i] > array[i + 1]) {
            auto turbulenceLength = countTurbulenceNegative(array, i);
            i += turbulenceLength;
            turbulence = turbulence < turbulenceLength ? turbulenceLength : turbulence;
        }
        i++;
    }
    return turbulence;
}

int Turbulence::countTurbulencePositive(std::vector<int> &array, size_t position) {
    if(position > array.size() - 2)
        return position;

    if(array[position] < array[position + 1])
        return countTurbulencePositive(array, position + 2);

    return position;
}

int Turbulence::countTurbulenceNegative(std::vector<int> &array, size_t position) {
    if(position > array.size() - 2)
        return position;

    if(array[position] > array[position + 1]) {
        return countTurbulenceNegative(array, position + 2);
    }
    return position;
}
