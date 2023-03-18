#include "node.h"

Node::Node(int value, Node *left, Node *right)
    : left(left), right(right), value(value) {
}
