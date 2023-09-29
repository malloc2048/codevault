#include "linked_list.h"

bool LinkedList::is_palindrome(Node<int> *l) {
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

Node<int> * LinkedList::remove_from_list(Node<int> * l, int k){
    // find the node
    auto node = l;
    Node<int>* previous = nullptr;

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

Node<int> * LinkedList::add_two_huge_numbers(Node<int> * a, Node<int> * b) {
    return nullptr;
}
