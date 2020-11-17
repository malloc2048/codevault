#include "amazon.h"
#include <gtest/gtest.h>

int Amazon::find_largest_turbulence_period(std::vector<int>& array) {
    if(array.size() <= 1)
        return 0;

    size_t i = 0;
    int turbulence = 0;

    while(i < array.size() - 1) {
        if(array[i] < array[i + 1]) {
            auto turbulenceLength = count_turbulence_positive(array, i);
            i += turbulenceLength;
            turbulence = turbulence < turbulenceLength ? turbulenceLength : turbulence;
        } else if(array[i] > array[i + 1]) {
            auto turbulenceLength = count_turbulence_negative(array, i);
            i += turbulenceLength;
            turbulence = turbulence < turbulenceLength ? turbulenceLength : turbulence;
        }
        i++;
    }
    return turbulence;
}

int Amazon::count_turbulence_positive(std::vector<int>& array, size_t position) {
    if(position > array.size() - 2)
        return position;

    if(array[position] < array[position + 1])
        return count_turbulence_positive(array, position + 2);

    return position;
}

int Amazon::count_turbulence_negative(std::vector<int>& array, size_t position) {
    if(position > array.size() - 2)
        return position;

    if(array[position] > array[position + 1]) {
        return count_turbulence_negative(array, position + 2);
    }
    return position;
}

TEST(AmazonTest, Turbulence) {
    std::vector<int> arrayLowToHigh = {50, 100, 50, 100, 50, 100};
    ASSERT_EQ(6, Amazon::find_largest_turbulence_period(arrayLowToHigh));

    std::vector<int> arrayNoTurbulence = {50, 50, 50, 50, 50, 50, 50};
    ASSERT_EQ(0, Amazon::find_largest_turbulence_period(arrayNoTurbulence));

    std::vector<int> arrayHighToLow = {100, 50, 100, 50, 50};
    ASSERT_EQ(4, Amazon::find_largest_turbulence_period(arrayHighToLow));
}
