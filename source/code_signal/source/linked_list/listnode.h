#ifndef CODESIGNAL_LISTNODE_H
#define CODESIGNAL_LISTNODE_H

#include <vector>
#include <iostream>

// Definition for singly-linked list:
namespace linkedlist {
    template<typename T>
    struct ListNode {
        explicit ListNode(const T &v) : value(v), next(nullptr) {}
        void showList(){
            std::cout << value << " ";
            if(next != nullptr) {
                next->showList();
            } else {
                std::cout << "end" << std::endl;
            }
        }

        T value;
        ListNode *next;
    };

    template<typename T>
    ListNode<T>* makelist(const std::vector<T>& values) {
        if(values.empty()) {
            return nullptr;
        }
        auto root = new ListNode<T>(values[0]);
        auto next = &root->next;

        auto iter = values.begin();
        for(std::advance(iter, 1); iter != values.end(); ++iter) {
            auto node = new ListNode<T>(*iter);
            *next = node;
            next = &node->next;
        }
        return root;
    }
}
#endif 
