#ifndef CODESIGNAL_GAPDISTANCE_H
#define CODESIGNAL_GAPDISTANCE_H

#include <vector>

class GapDistance {
public:
    GapDistance() = default;
    ~GapDistance() = default;

    int findSmallestGapDistance(std::vector<int>& array);

private:
    int gapDistance;
};
#endif
