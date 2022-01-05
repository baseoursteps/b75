#include <cstddef>
#include <iostream>
#include <vector>

#include "tree.h"

using namespace std;

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.

template<typename T>
size_t
depth(const typename Tree<T>::Child root)
{
    if (auto locked = root.lock())
        return 1 + max(depth<T>(locked->left), depth<T>(locked->right));
    else
        return 0;
}

template<typename T>
size_t
depth(const typename Tree<T>::List &list)
{
    auto [elems, root] = Tree<size_t>::from_list(list);

    cout << root;

    return depth<T>(root);
}

int
main()
{
    // 4
    Tree<size_t>::List vals0 { 3,  9,  20, {}, {}, 15, 7, {},
                               {}, {}, {}, {}, {}, 1,  2 };

    // 3
    Tree<size_t>::List vals1 { 3, 9, 20, {}, {}, 15, 7 };

    // 2
    Tree<size_t>::List vals2 { 1, {}, 2 };

    // 1
    Tree<size_t>::List vals3 { 3 };

    cout << depth<size_t>(vals0) << "\n";
}
