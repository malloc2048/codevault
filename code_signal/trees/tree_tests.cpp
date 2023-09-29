#include "trees/tree.h"
#include <gtest/gtest.h>

Node<int>* makeTreeNode(int value) {
    auto tree = new Node<int>(value);
    return tree;
}

Node<int>* makeTree(int val) {
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

TEST(TreesTest, HasPathWithGivenSum) {
    auto tree = makeTree(4);

    // tree is nullptr
    ASSERT_FALSE(Tree::has_path_with_given_sum(nullptr, 2));

    // Path exists
    ASSERT_TRUE(Tree::has_path_with_given_sum(tree, 7));

    // No Path
    ASSERT_FALSE(Tree::has_path_with_given_sum(tree, 27));

    // Total exists in subtree, but not complete root->leaf
    ASSERT_FALSE(Tree::has_path_with_given_sum(tree, 3));
}
