#include "node.h"
#include "tree.h"
#include "gtest/gtest.h"

TEST(TreeTest, ConstructNode) {
    Node node;
    ASSERT_EQ(nullptr, node.left);
    ASSERT_EQ(nullptr, node.right);
    ASSERT_EQ(0, node.value);

    Node node2(22);
    ASSERT_EQ(nullptr, node2.left);
    ASSERT_EQ(nullptr, node2.right);
    ASSERT_EQ(22, node2.value);

    Node node3(33, &node, &node2);
    ASSERT_EQ(&node, node3.left);
    ASSERT_EQ(&node2, node3.right);
    ASSERT_EQ(33, node3.value);
}

TEST(TreeTest, AddNodes) {
    Tree tree;
    ASSERT_TRUE(tree.Empty());

    auto node = tree.AddValue(22);
    ASSERT_FALSE(tree.Empty());
    ASSERT_EQ(nullptr, node->left);
    ASSERT_EQ(nullptr, node->right);
    ASSERT_EQ(22, node->value);

    auto node2 = tree.AddValue(11);
    ASSERT_EQ(nullptr, node2->left);
    ASSERT_EQ(nullptr, node2->right);
    ASSERT_EQ(11, node2->value);
    ASSERT_EQ(node2, node->left);
    ASSERT_EQ(nullptr, node->right);

    auto nodeDuplicate = tree.AddValue(11);
    ASSERT_EQ(node2, nodeDuplicate);

    auto node3 = tree.AddValue(33);
    ASSERT_EQ(nullptr, node3->left);
    ASSERT_EQ(nullptr, node3->right);
    ASSERT_EQ(33, node3->value);
    ASSERT_EQ(node2, node->left);
    ASSERT_EQ(node3, node->right);
}

TEST(TreeTest, DepthWalkTree) {
    Tree tree;
    std::vector<int> walkValues;
    tree.DepthWalk(walkValues);
    ASSERT_TRUE(walkValues.empty());

    auto root = tree.AddValue(22);
    auto left = tree.AddValue(11);
    auto right = tree.AddValue(33);

    tree.DepthWalk(walkValues);
    ASSERT_TRUE(walkValues.size() == 3);
    ASSERT_EQ(11, walkValues[0]);
    ASSERT_EQ(22, walkValues[1]);
    ASSERT_EQ(33, walkValues[2]);

    tree.AddValue(44);
    tree.AddValue(55);
    tree.AddValue(0);
    walkValues.clear();
    tree.DepthWalk(walkValues);

    ASSERT_TRUE(walkValues.size() == 6);
    ASSERT_EQ(0, walkValues[0]);
    ASSERT_EQ(11, walkValues[1]);
    ASSERT_EQ(22, walkValues[2]);
    ASSERT_EQ(33, walkValues[3]);
    ASSERT_EQ(44, walkValues[4]);
    ASSERT_EQ(55, walkValues[5]);
}

TEST(TreeTest, BreadthWalkTest) {
    Tree tree;
    std::vector<int> walkValues;
    tree.BreadthWalk(walkValues);
    ASSERT_TRUE(walkValues.empty());

    auto root = tree.AddValue(22);
    auto left = tree.AddValue(11);
    auto right = tree.AddValue(33);
    auto leftLeft = tree.AddValue(0);
    auto rightRight = tree.AddValue(44);
    auto rightLeftRight = tree.AddValue(5);

    tree.BreadthWalk(walkValues);
    ASSERT_TRUE(walkValues.size() == 6);
    ASSERT_EQ(22, walkValues[0]);
    ASSERT_EQ(11, walkValues[1]);
    ASSERT_EQ(33, walkValues[2]);
    ASSERT_EQ(0, walkValues[3]);
    ASSERT_EQ(44, walkValues[4]);
    ASSERT_EQ(5, walkValues[5]);
}

TEST(TreeTest, AlternatingBreadthWalkTest) {
    Tree tree;
    std::vector<int> walkValues;
    tree.AlternatingBreadthWalk(walkValues);
    ASSERT_TRUE(walkValues.empty());

    auto root = tree.AddValue(22);
    auto left = tree.AddValue(11);
    auto right = tree.AddValue(33);
    auto leftLeft = tree.AddValue(0);
    auto rightRight = tree.AddValue(44);
    auto rightLeftRight = tree.AddValue(5);

    tree.AlternatingBreadthWalk(walkValues);
    ASSERT_TRUE(walkValues.size() == 6);

    std::cout << std::endl;
    for(auto& val: walkValues)
        std::cout << val << " ";
    std::cout << std::endl;

//    ASSERT_EQ(22, walkValues[0]);
//    ASSERT_EQ(33, walkValues[1]);
//    ASSERT_EQ(11, walkValues[2]);
//    ASSERT_EQ(0, walkValues[3]);
//    ASSERT_EQ(44, walkValues[4]);
//    ASSERT_EQ(5, walkValues[5]);
}
