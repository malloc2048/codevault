#include <gtest/gtest.h>
#include "linkedlist.h"

bool compareList(linkedlist::ListNode<int>* list, const std::vector<int>& values) {
    for(auto value: values) {
        if(list == nullptr) {
            return false;
        }
        if(list->value != value) {
            return false;
        }
        list = list->next;
    }
    return true;
}

TEST(LinkedListTest, RemoveFromList) {
    auto root = linkedlist::makelist<int>(std::vector<int>{ 3, 1, 2, 3, 4, 5 });
    auto result = linkedlist::removeKFromList(root, 3);
    ASSERT_TRUE(compareList(result, std::vector<int>{ 1, 2, 4, 5 }));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 2, 3, 4, 5, 6, 7 });
    result = linkedlist::removeKFromList(root, 10);
    ASSERT_TRUE(compareList(result, std::vector<int>{ 1, 2, 3, 4, 5, 6, 7 }));

    root = linkedlist::makelist<int>(std::vector<int>{ 1000, 1000 });
    result = linkedlist::removeKFromList(root, 1000);
    ASSERT_TRUE(compareList(result, std::vector<int>{ }));

    root = linkedlist::makelist<int>(std::vector<int>{ });
    result = linkedlist::removeKFromList(root, -1000);
    ASSERT_TRUE(compareList(result, std::vector<int>{ }));

    root = linkedlist::makelist<int>(std::vector<int>{ 123, 456, 789, 0 });
    result = linkedlist::removeKFromList(root, 0);
    ASSERT_TRUE(compareList(result, std::vector<int>{ 123, 456, 789 }));
}

TEST(LinkedListTest, IsListPalindrome) {
    auto root = linkedlist::makelist<int>(std::vector<int>{ 0, 1, 0 });
    ASSERT_TRUE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 2, 2, 3 });
    ASSERT_FALSE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 1000000000, -1000000000, -1000000000, 1000000000, 1 });
    ASSERT_TRUE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 2, 3, 3, 2 });
    ASSERT_FALSE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 2, 3, 1, 2, 3 });
    ASSERT_FALSE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ });
    ASSERT_TRUE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 3, 5, 3, 5 });
    ASSERT_FALSE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 5, 2, 4 });
    ASSERT_FALSE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 10 });
    ASSERT_TRUE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 0, 0 });
    ASSERT_TRUE(linkedlist::isListPalindrome(root));

    root = linkedlist::makelist<int>(std::vector<int>{ 1, 3, 2, 2, 2 });
    ASSERT_FALSE(linkedlist::isListPalindrome(root));
}
