#ifndef CODESIGNAL_TREE_H
#define CODESIGNAL_TREE_H

#include "node.h"
#include <vector>

class Tree {
public:
    Tree() = default;
    ~Tree() = default;
    explicit Tree(Node* root);

    bool Empty() const;
    Node* AddValue(int val);
    void DepthWalk(std::vector<int>& values);
    void BreadthWalk(std::vector<int>& values);
    void AlternatingBreadthWalk(std::vector<int>& values);

protected:
    static Node* insert(int val, Node* parent);
    static void walk(std::vector<int>& values, Node* node);
    static void breadthWalk(std::vector<int>& values, std::vector<Node*>& nodes);
    static void altenatingBreadthWalk(std::vector<int>& values, std::vector<Node*>& nodesLeft, std::vector<Node*>& nodesRight);

    static void leftBreadthWalk(std::vector<int>& values, std::vector<Node*>& nodesLeft, std::vector<Node*>& nodesRight);
    static void rightBreadthWalk(std::vector<int>& values, std::vector<Node*>& nodesLeft, std::vector<Node*>& nodesRight);

private:
    Node* root = nullptr;
};
#endif
