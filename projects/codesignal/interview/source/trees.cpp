#include "trees.h"
#include <iostream>

namespace trees {
    bool hasDuplicateSubTree(Tree<int>* t) {
        return false;
    }

    bool sum(Tree<int>* t, int total, int target) {
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

    bool hasPathWithGivenSum(Tree<int> * t, int s) {
        if(nullptr == t){
            return false;
        }
        return sum(t, 0, s);
    }

    bool isTreeSymmetric(Tree<int> * t) {
        return false;
    }
}
