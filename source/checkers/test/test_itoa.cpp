#include "gtest/gtest.h"

void reverse(char* string, int size)
{
    int left = 0;
    int right = size;
    while(left < right) {
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;

        left++;
        right--;
    }
}

char* Itoa(int number, char* string)
{
    if(nullptr == string)
        string = new char[11];

    bool isNegative(false);
    if(number < 0) {
        isNegative = true;
        number *= -1;
    }

    int index = 0;
    const int MASK = 10;
    do {
        int digit = number % MASK;
        string[index] = (char)('0' + digit);
        number /= 10;
        index++;
    } while(number > 0);
    if(isNegative)
        string[index++] = '-';
    string[index] = '\0';

    reverse(string, index - 1);

    return string;
}

TEST(ItoaTest, NullPtr_ReturnZero)
{
    ASSERT_STREQ("0", Itoa(0, nullptr));
}

TEST(ItoaTest, ReturnANumber_Positive)
{
    ASSERT_STREQ("42", Itoa(42, nullptr));
}

TEST(ItoaTest, ReturnANumber_Negative)
{
    ASSERT_STREQ("-42", Itoa(-42, nullptr));
}
