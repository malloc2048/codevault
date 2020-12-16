#ifndef INTERVIEW_NODE_H
#define INTERVIEW_NODE_H

template <class T>
class Node {
public:
    explicit Node(T value_);
    void insert(T value_);

    T value;
    Node* left;
    Node* right;
    Node* parent;

protected:
    void insertLeft(T value_);
    void insertRight(T value_);
};
#endif
