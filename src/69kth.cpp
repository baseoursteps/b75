#include <iostream>

#include "tree.h"

using namespace std;

// Given the root of a binary search tree, and an integer k, return the kth
// smallest value (1-indexed) of all the values of the nodes in the tree.

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// post-order traversal i guess

template<typename T>
bool
_get_kth(typename Tree<T>::Child root, size_t &kth, T &val)
{
    auto locked = root.lock();

    if (!locked)
        return false;

    if (_get_kth<T>(locked->left, kth, val))
        return true;

    if (kth-- == 1) {
        val = locked->val;
        return true;
    }

    if (_get_kth<T>(locked->right, kth, val))
        return true;

    return false;
}

template<typename T>
T
get_kth(typename Tree<T>::List const &list, size_t kth)
{
    auto [elems, root] = Tree<T>::from_list(list);
    T val {};

    if (!_get_kth(root, kth, val))
        cout << "not enough elements in tree\n";

    return val;
}

int
main()
{
    // k=1, out = 1
    Tree<int>::List t1 { 3, 1, 4, {}, 2 };

    // k=3, out = 3
    Tree<int>::List t2 { 5, 3, 6, 2, 4, {}, {}, 1 };

    cout << get_kth<int>(t1, 1) << get_kth<int>(t2, 3) << "\n";
}
