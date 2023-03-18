#include "level2.h"
#include <gtest/gtest.h>

TEST(IntroLevel2Test, AdjacentElementsProduct) {
    ASSERT_EQ(2, level2::adjacentElementsProduct(std::vector<int>{-1, -2}));
    ASSERT_EQ(6, level2::adjacentElementsProduct(std::vector<int>{1, 2, 3, 0}));
    ASSERT_EQ(6, level2::adjacentElementsProduct(std::vector<int>{4, 1, 2, 3, 1, 5}));
    ASSERT_EQ(6, level2::adjacentElementsProduct(std::vector<int>{5, 1, 2, 3, 1, 4}));
    ASSERT_EQ(0, level2::adjacentElementsProduct(std::vector<int>{1, 0, 1, 0, 1000}));
    ASSERT_EQ(21, level2::adjacentElementsProduct(std::vector<int>{3, 6, -2, -5, 7, 3}));
    ASSERT_EQ(-12, level2::adjacentElementsProduct(std::vector<int>{-23, 4, -3, 8, -12}));
    ASSERT_EQ(30, level2::adjacentElementsProduct(std::vector<int>{5, 6, -4, 2, 3, 2, -23}));
    ASSERT_EQ(50, level2::adjacentElementsProduct(std::vector<int>{9, 5, 10, 2, 24, -1, -48}));
}

TEST(IntroLevel2Test, ShapeArea) {
    ASSERT_EQ(5, level2::shapeArea(2));
    ASSERT_EQ(1, level2::shapeArea(1));
    ASSERT_EQ(41, level2::shapeArea(5));
    ASSERT_EQ(13, level2::shapeArea(3));
    ASSERT_EQ(19801, level2::shapeArea(100));
    ASSERT_EQ(97986001, level2::shapeArea(7000));
    ASSERT_EQ(127984001, level2::shapeArea(8000));
    ASSERT_EQ(199940005, level2::shapeArea(9999));
    ASSERT_EQ(199900013, level2::shapeArea(9998));
    ASSERT_EQ(161946005, level2::shapeArea(8999));
}

TEST(IntroLevel2Test, MakeArrayConsecutive2){
    ASSERT_EQ(0, level2::makeArrayConsecutive2(std::vector<int>{ 1 }));
    ASSERT_EQ(2, level2::makeArrayConsecutive2(std::vector<int>{ 0, 3 }));
    ASSERT_EQ(2, level2::makeArrayConsecutive2(std::vector<int>{ 6, 3 }));
    ASSERT_EQ(0, level2::makeArrayConsecutive2(std::vector<int>{ 5, 4, 6 }));
    ASSERT_EQ(3, level2::makeArrayConsecutive2(std::vector<int>{ 6, 2, 3, 8 }));
}

TEST(IntroLevel2Test, AlmostIncreasingSequence){
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 1, 1 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 1, 3, 2 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 0, -2, 5, 6 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 1, 2, 5, 3, 5 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 3, 5, 67, 98,  }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 1, 2, 3, 4, 3, 6 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 10, 1, 2, 3, 4, 5 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 1, 2, 3, 4, 99, 5, 6 }));
    ASSERT_TRUE(level2::almostIncreasingSequence(std::vector<int>{ 123, -17, -5, 1, 2, 3, 12, 43, 45 }));

    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 3, 2, 1 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 2, 1, 2 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 2, 5, 5, 5 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 1, 1, 2, 3 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 4, 10, 4, 2 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 1, 2, 3, 4, 4 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 3, 6, 5, 8, 10, 20, 15 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 1, 2, 3, 4, 5, 3, 5, 6 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 40, 50, 60, 10, 20, 30 }));
    ASSERT_FALSE(level2::almostIncreasingSequence(std::vector<int>{ 10, 1, 2, 3, 4, 5, 6, 1 }));
}

TEST(IntroLevel2Test, MatrixElementsSum) {
    ASSERT_EQ(9, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 0,1,1,2 },
        { 0,5,0,0 },
        { 2,0,3,3 }
    }));

    ASSERT_EQ(9, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 1,1,1,0 },
        { 0,5,0,1 },
        { 2,1,3,10 }
    }));

    ASSERT_EQ(18, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 1,1,1 },
        { 2,2,2 },
        { 3,3,3 }
    }));

    ASSERT_EQ(0, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 0 }
    }));

    ASSERT_EQ(5, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 1,0,3 },
        { 0,2,1 },
        { 1,2,0 }
    }));

    ASSERT_EQ(6, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 1 },
        { 5 },
        { 0 },
        { 2 }
    }));

    ASSERT_EQ(15, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 1,2,3,4,5 }
    }));

    ASSERT_EQ(17, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 2 },
        { 5 },
        { 10 }
    }));

    ASSERT_EQ(15, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 4,0,1 },
        { 10,7,0 },
        { 0,0,0},
        { 9,1,2 }
    }));

    ASSERT_EQ(1, level2::matrixElementsSum(std::vector<std::vector<int>>{
        { 1 }
    }));
}
