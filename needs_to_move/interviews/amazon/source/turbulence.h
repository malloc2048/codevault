#ifndef CODESIGNAL_TURBULENCE_H
#define CODESIGNAL_TURBULENCE_H

#include <cstdlib>
#include <vector>

class Turbulence {
public:
    Turbulence() = default;
    ~Turbulence() = default;

    int findLargestTurbulencePeriod(std::vector<int>& array);

private:
    int countTurbulencePositive(std::vector<int>& array, size_t position);
    int countTurbulenceNegative(std::vector<int>& array, size_t position);
};
#endif
