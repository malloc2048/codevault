#ifndef CODEVAULT_LINKED_LIST_H
#define CODEVAULT_LINKED_LIST_H

#include <vector>
#include <iostream>

template<typename T>
struct Node {
    explicit Node(const T &v) : value(v), next(nullptr) {}

    void showList(){
        std::cout << value << " ";
        if(next != nullptr) {
            next->showList();
        } else {
            std::cout << "end" << std::endl;
        }
    }

    T value;
    Node *next;
};

template<typename T>
Node<T>* make_list(const std::vector<T>& values) {
    if(values.empty()) {
        return nullptr;
    }
    auto root = new Node<T>(values[0]);
    auto next = &root->next;

    auto iter = values.begin();
    for(std::advance(iter, 1); iter != values.end(); ++iter) {
        auto node = new Node<T>(*iter);
        *next = node;
        next = &node->next;
    }
    return root;
}

class LinkedList {
public:
    LinkedList() = default;
    ~LinkedList() = default;

    static bool is_palindrome(Node<int> * l);
    static Node<int> * remove_from_list(Node<int> * l, int k);
    static Node<int> * add_two_huge_numbers(Node<int> * a, Node<int> * b);
};
#endif
