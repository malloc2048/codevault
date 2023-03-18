#ifndef CODESIGNAL_LINKEDLIST_H
#define CODESIGNAL_LINKEDLIST_H

#include "listnode.h"

namespace linkedlist {
    // Note: Try to solve this task in O(n) time using O(1) additional space,
    // where n is the number of elements in the list, since this is what you'll be asked to do during an interview.
    // Given a singly linked list of integers l and an integer k,
    // remove all elements from list l that have a value equal to k.
    ListNode<int> * removeKFromList(ListNode<int> * l, int k);

    // Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l,
    // since this is what you'll be asked to do during an interview.
    // Given a singly linked list of integers, determine whether or not it's a palindrome.
    bool isListPalindrome(ListNode<int> * l);

    // You're given 2 huge integers represented by linked lists.
    // Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits.
    // The represented number might have leading zeros.
    // Your task is to add up these huge integers and return the result in the same format
    ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b);
}
#endif
