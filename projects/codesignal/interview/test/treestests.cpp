#include <gtest/gtest.h>
#include "trees.h"

trees::Tree<int>* makeTreeNode(int value) {
    auto tree = new trees::Tree<int>(value);
    return tree;
}

trees::Tree<int>* makeTree(int val) {
    auto tree = makeTreeNode(val); // this is root

    tree->left = makeTreeNode(1);
    tree->left->left = makeTreeNode(-2);
    tree->left->left->right = makeTreeNode(3);

    tree->right = makeTreeNode(3);
    tree->right->left = makeTreeNode(1);
    tree->right->right = makeTreeNode(2);
    tree->right->right->left = makeTreeNode(-2);
    tree->right->right->right = makeTreeNode(-3);

    return tree;
}

TEST(InterviewTreesTest, HasPathWithGivenSum) {
    auto tree = makeTree(4);

    // tree is nullptr
    ASSERT_FALSE(trees::hasPathWithGivenSum(nullptr, 2));

    // Path exists
    ASSERT_TRUE(trees::hasPathWithGivenSum(tree, 7));

    // No Path
    ASSERT_FALSE(trees::hasPathWithGivenSum(tree, 27));

    // Total exists in subtree, but not complete root->leaf
    ASSERT_FALSE(trees::hasPathWithGivenSum(tree, 3));
}
