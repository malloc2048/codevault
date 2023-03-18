#ifndef CODESIGNAL_TREE_H
#define CODESIGNAL_TREE_H

namespace trees {
    template<typename T>
    struct Tree {
        explicit Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}

        T value;
        Tree *left;
        Tree *right;
    };
}
#endif
