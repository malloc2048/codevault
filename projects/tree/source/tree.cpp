#include "tree.h"

Tree::Tree(Node *root) : root(root) {

}

bool Tree::Empty() const {
    return root == nullptr;
}

Node* Tree::AddValue(int val) {
    if(root == nullptr) {
        root = new Node(val);
        return root;
    }
    return insert(val, root);
}

void Tree::DepthWalk(std::vector<int>& values) {
    if(root != nullptr)
        walk(values, root);
}

void Tree::BreadthWalk(std::vector<int>& values) {
    if(root != nullptr) {
        std::vector<Node*> nodes = {root};
        breadthWalk(values, nodes);
    };
}

Node *Tree::insert(int val, Node *parent) {
    if(parent->value > val) {
        if(parent->left == nullptr) {
            parent->left = new Node(val);
            return parent->left;
        } else {
            return insert(val, parent->left);
        }
    } else if(parent->value < val) {
        if(parent->right == nullptr) {
            parent->right = new Node(val);
            return parent->right;
        } else {
            return insert(val, parent->right);
        }
    } else {
        return parent;
    }
}

void Tree::walk(std::vector<int>& values, Node* node) {
    if(node == nullptr)
        return;

    if(node->left != nullptr) {
        walk(values, node->left);
    }
    values.push_back(node->value);
    if(node->right != nullptr) {
        walk(values, node->right);
    }
}

void Tree::breadthWalk(std::vector<int>& values, std::vector<Node*>& nodes) {
    if(nodes.empty())
        return;

    Node* node = nodes.front();
    nodes.erase(nodes.begin());

    values.push_back(node->value);
    if(node->left != nullptr)
        nodes.push_back(node->left);
    if(node->right != nullptr)
        nodes.push_back(node->right);

    breadthWalk(values, nodes);
}

void Tree::AlternatingBreadthWalk(std::vector<int>& values) {
    if(root != nullptr) {
        std::vector<Node*> nodesLeft = { root };
        std::vector<Node*> nodesRight;

        altenatingBreadthWalk(values, nodesLeft, nodesRight);
    }
}

void Tree::altenatingBreadthWalk(std::vector<int> &values, std::vector<Node *>& nodesLeft, std::vector<Node *> &nodesRight) {
    while(!nodesLeft.empty() || !nodesRight.empty()) {
        if (!nodesLeft.empty()) {
            leftBreadthWalk(values, nodesLeft, nodesRight);
        } else if(!nodesRight.empty()) {
            rightBreadthWalk(values, nodesLeft, nodesRight);
        }
    }
}

void Tree::leftBreadthWalk(std::vector<int> &values, std::vector<Node *> &nodesLeft, std::vector<Node *> &nodesRight) {
    if(nodesLeft.empty())
        return;

    auto node = nodesLeft.front();
    nodesLeft.erase(nodesLeft.begin());

    values.push_back(node->value);

    if(node->left != nullptr)
        nodesRight.insert(nodesRight.begin(), node->left);
    if(node->right != nullptr)
        nodesRight.insert(nodesRight.begin(), node->right);
    leftBreadthWalk(values, nodesLeft, nodesRight);
}

void Tree::rightBreadthWalk(std::vector<int> &values, std::vector<Node *> &nodesLeft, std::vector<Node *> &nodesRight) {
    if(nodesRight.empty())
        return;

    auto node = nodesRight.front();
    nodesRight.erase(nodesRight.begin());

    values.push_back(node->value);

    if(node->right != nullptr)
        nodesRight.insert(nodesRight.begin(), node->right);
    if(node->left != nullptr)
        nodesRight.insert(nodesRight.begin(), node->left);
    rightBreadthWalk(values, nodesLeft, nodesRight);
}