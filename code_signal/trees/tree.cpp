#include "tree.h"

bool Tree::is_symmetric(Node<int> * t) {
    return false;
}

bool Tree::has_duplicate_subtree(Node<int>* t) {
    return false;
}

bool Tree::sum(Node<int>* t, int total, int target) {
    if(t->left == nullptr && t->right == nullptr) {
        return (total + t->value) == target;
    }

    if(t->left == nullptr) {
        return sum(t->right, total + t->value, target);
    }

    if(t->right == nullptr) {
        return sum(t->left, total + t->value, target);
    }
    return sum(t->left, total + t->value, target) || sum(t->right, total + t->value, target);
}

bool Tree::has_path_with_given_sum(Node<int> * t, int s) {
    if(nullptr == t){
        return false;
    }
    return sum(t, 0, s);
}
