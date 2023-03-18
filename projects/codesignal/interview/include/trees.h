#ifndef CODESIGNAL_TREES_H
#define CODESIGNAL_TREES_H

#include "tree.h"

namespace trees {
    // From Axon
    // Given a binary tree t, determine if there is a duplicate sub-tree
    bool hasDuplicateSubTree(Tree<int>* t);

    // Given a binary tree t and an integer s,
    // determine whether there is a root to leaf path in t such that the sum of vertex values equals s.
    bool hasPathWithGivenSum(Tree<int> * t, int s);

    // Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.
    bool isTreeSymmetric(Tree<int> * t);
}
#endif
