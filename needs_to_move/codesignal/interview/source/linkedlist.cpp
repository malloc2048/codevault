#include "linkedlist.h"

namespace linkedlist {
    ListNode<int> * removeKFromList(ListNode<int> * l, int k){
        // find the node
        auto node = l;
        ListNode<int>* previous = nullptr;

        while(node != nullptr) {
            if(node->value == k) {
                if(nullptr == previous){
                    l = node->next;
                } else {
                    previous->next = node->next;
                }
            } else {
                previous = node;
            }
            node = node->next;
        }
        return l;
    }

    bool isListPalindrome(ListNode<int> * l){
        auto node = l;
        std::vector<int> values;
        while(node != nullptr) {
            values.push_back(node->value);
            node = node->next;
        }

        if(!values.empty()) {
            for(size_t front = 0, back = values.size() - 1; front < back; front++, back--) {
                if(values[front] != values[back]) {
                    return false;
                }
            }
        }
        return true;
    }

    ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
        return nullptr;
    }
}