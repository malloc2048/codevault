#ifndef INTERVIEW_TREE_H
#define INTERVIEW_TREE_H

#include <map>
#include <cstdint>
#include "node.h"

template <class  T>
class Tree {
public:
    Tree();

    void insert(T value);
    void fromArray(T* array, uint32_t length);

    bool hasNode(T value) const;
    uint32_t getNodeCount() const;
    int pathLength(T start, T end) const;

protected:
    uint32_t countNodes(Node<T>* node) const;
    Node<T>* findNode(Node<T>* node, T value) const;
    int findPath(Node<T>* node, T target, std::map<Node<T>*, bool>& visited) const;

private:
    Node<T>* root;
};
#endif
