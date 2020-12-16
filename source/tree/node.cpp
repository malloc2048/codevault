#include "node.h"

template <class T> Node<T>::Node(T value_) : value(value_), left(nullptr), right(nullptr), parent(nullptr) {}

template <class T> void Node<T>::insert(T value_) {
    if(value < value_)
        insertRight(value_);
    if(value > value_)
        insertLeft(value_);
}

template <class T> void Node<T>::insertLeft(T value_) {
    if(nullptr == left) {
        left = new Node<int>(value_);
        left->parent = this;
    } else {
        left->insert(value_);
    }
}

template <class T> void Node<T>::insertRight(T value_) {
    if(nullptr == right) {
        right = new Node<int>(value_);
        right->parent = this;
    } else {
        right->insert(value_);
    }
}

template class Node<int>;