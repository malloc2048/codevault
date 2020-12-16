#include "tree.h"

template <class T> Tree<T>::Tree() : root(nullptr) {}

template <class T> void Tree<T>::insert(T value) {
    if(nullptr != root )
        root->insert(value);
}

template <class T> void Tree<T>::fromArray(T* array, uint32_t length) {
    if(nullptr == root && length > 0) {
        root = new Node<T>(array[0]);
        for(uint32_t i = 1; i < length; i++) {
            insert(array[i]);
        }
    }
}

template <class T> bool Tree<T>::hasNode(T value) const {
    if(nullptr != root) {
        return findNode(root, value) != nullptr;
    }
    return false;
}

template <class T> uint32_t Tree<T>::getNodeCount() const {
    uint32_t count = 0;
    if(nullptr != root) {
        count = countNodes(root);
    }
    return count;
}

template <class T> int Tree<T>::pathLength(T start, T end) const {
    if(start == end)
        return 0;

    if(nullptr != root) {
        Node<T>* endNode = findNode(root, end);
        Node<T>* startNode = findNode(root, start);
        if(nullptr != startNode && nullptr != endNode) {
            std::map<Node<T>*, bool> visited;
            return findPath(startNode, end, visited);
        }
    }
    return -1;
}


template <class T> uint32_t Tree<T>::countNodes(Node<T> *node) const {
    uint32_t count = 1;
    if(nullptr != node->left)
        count += countNodes(node->left);
    if(nullptr != node->right)
        count += countNodes(node->right);

    return count;
}

template <class T> int Tree<T>::findPath(Node<T>* node, T target, std::map<Node<T>*, bool>& visited) const {
    visited[node] = true;
    if(node->value < target) {
        if (nullptr != node->right) {
            if (visited.end() == visited.find(node->right)) {
                return findPath(node->right, target, visited) + 1;
            } else if(nullptr != node->parent) {
                if (visited.end() == visited.find(node->parent))
                    return findPath(node->parent, target, visited) + 1;
            }
        } else if(nullptr != node->parent) {
            if (visited.end() == visited.find(node->parent))
                return findPath(node->parent, target, visited) + 1;
        }
    }

    if(node->value > target) {
        if (nullptr != node->left) {
            if (visited.end() == visited.find(node->left)) {
                return findPath(node->left, target, visited) + 1;
            } else if(nullptr != node->parent) {
                if (visited.end() == visited.find(node->parent))
                    return findPath(node->parent, target, visited) + 1;
            }
        } else if (nullptr != node->parent) {
            if (visited.end() == visited.find(node->parent))
                return findPath(node->parent, target, visited) + 1;
        }
    }
    return 0;
}

template <class T> Node<T>* Tree<T>::findNode(Node<T>* node, T value) const {
    if(node->value == value)
        return node;
    if(node->value < value && node->right != nullptr)
        return findNode(node->right, value);
    if(node->value > value && node->left != nullptr)
        return findNode(node->left, value);
    return nullptr;
}

template class Tree<int>;
