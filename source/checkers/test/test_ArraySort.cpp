#include <gtest/gtest.h>

#include <iostream>

void orderArray(int array[], int size)
{
    int left = 0;
    int right = size - 1;
    while(left < right){

        if(array[left] == 1 && array[right] == 0) {
            array[left] = 0;
            array[right] = 1;
        }
        while(array[left] == 0)
            left++;
        while(array[right] == 1)
            right--;
    }
}

TEST(ArraySortTest, RandomOrder)
{
    int array[5] = {0, 1, 1, 0, 0};
    int expected[5] = {0, 0, 0, 1, 1};
    orderArray(array, 5);

    for(int i = 0; i < 5; i++) {
        ASSERT_EQ(expected[i], array[i]);
    }
}

TEST(ArraySortTest, OnesFirstOrder)
{
    int array[5] = {1, 1, 1, 0, 0};
    int expected[5] = {0, 0, 1, 1, 1};
    orderArray(array, 5);

    for(int i = 0; i < 5; i++) {
        ASSERT_EQ(expected[i], array[i]);
    }
}

TEST(ArraySortTest, AllOnesOrder)
{
    int array[5] = {1, 1, 1, 1, 1};
    int expected[5] = {1, 1, 1, 1, 1};
    orderArray(array, 5);

    for(int i = 0; i < 5; i++) {
        ASSERT_EQ(expected[i], array[i]);
    }
}

TEST(ArraySortTest, AllZerosOrder)
{
    int array[5] = {0, 0, 0, 0, 0};
    int expected[5] = {0, 0, 0, 0, 0};
    orderArray(array, 5);

    for(int i = 0; i < 5; i++) {
        ASSERT_EQ(expected[i], array[i]);
    }
}
