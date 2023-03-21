#include "turbulence.h"
#include "gapdistance.h"
#include "gtest/gtest.h"
#include "adjacentgroup.h"

TEST(AmazonTest, LargestAdjacentGroup) {
    std::vector<std::vector<int>> array = {
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 1}
    };

    AmazonProblems::AdjacentGroup ag;
    ASSERT_EQ(4, ag.findLargestAdjacentGroup(array));
}

TEST(AmazonTest, Turbulence) {
    Turbulence turbulence;

    std::vector<int> arrayLowToHigh = {50, 100, 50, 100, 50, 100};
    ASSERT_EQ(6, turbulence.findLargestTurbulencePeriod(arrayLowToHigh));

    std::vector<int> arrayNoTurbulence = {50, 50, 50, 50, 50, 50, 50};
    ASSERT_EQ(0, turbulence.findLargestTurbulencePeriod(arrayNoTurbulence));

    std::vector<int> arrayHighToLow = {100, 50, 100, 50, 50};
    ASSERT_EQ(4, turbulence.findLargestTurbulencePeriod(arrayHighToLow));

//    std::vector<int> arrayMixed = {100, 50, 100, 50, 40, 30, 40};
//    ASSERT_EQ(4, turbulence.findLargestTurbulencePeriod(arrayMixed));
}

TEST(AmazonTest, GapDistance) {
    GapDistance gapDistance;

    std::vector<int> arrayNoGap = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(1, gapDistance.findSmallestGapDistance(arrayNoGap));

    std::vector<int> arrayWithGap = {4, 8};
    ASSERT_EQ(4, gapDistance.findSmallestGapDistance(arrayWithGap));

    std::vector<int> arrayWithMultipleGaps = {1, 5, 9, 100};
    ASSERT_EQ(4, gapDistance.findSmallestGapDistance(arrayWithMultipleGaps));

    std::vector<int> emptyArray = {};
    ASSERT_EQ(-1, gapDistance.findSmallestGapDistance(emptyArray));

    std::vector<int> unsorted = {100, 200, 1, 55, 22, 88};
    ASSERT_EQ(12, gapDistance.findSmallestGapDistance(unsorted));
}
