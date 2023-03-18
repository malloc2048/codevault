#ifndef CODESIGNAL_NODE_H
#define CODESIGNAL_NODE_H

class Node {
public:
    Node() = default;
    ~Node() = default;

    explicit Node(int value, Node* left = nullptr, Node* right = nullptr);

    Node* left = nullptr;
    Node* right = nullptr;
    int value = 0;
};
#endif
