#ifndef CODEVAULT_TREE_H
#define CODEVAULT_TREE_H

template<typename T>
struct Node {
    explicit Node(const T &v) : value(v), left(nullptr), right(nullptr) {}

    T value;
    Node* left;
    Node* right;
};

class Tree {
public:
    Tree() = default;
    ~Tree() = default;

    static bool is_symmetric(Node<int> * t);
    static bool has_duplicate_subtree(Node<int>* t);
    static bool sum(Node<int>* t, int total, int target);
    static bool has_path_with_given_sum(Node<int> * t, int s);

private:

};
#endif
