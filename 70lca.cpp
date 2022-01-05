#include "tree.h"
#include <cstddef>
#include <iostream>
#include <optional>
#include <unordered_set>

using namespace std;

// Given a binary search tree (BST), find the lowest common ancestor (LCA) of
// two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants (where we allow a node to be a descendant of itself).”

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6

template<typename T>
optional<T>
get_lca(typename Tree<T>::Child root, T p, T q, size_t &found)
{
    if (found == 2)
        return {};

    auto locked = root.lock();
    if (!locked)
        return {};

    if (locked->val == p || locked->val == q) {
        found++;
        return locked->val;
    }

    auto left  = get_lca<T>(locked->left, p, q, found);
    auto right = get_lca<T>(locked->right, p, q, found);

    if (left && right)
        return locked->val;
    else if (left)
        return left;
    else if (right)
        return right;

    return {};
}

template<typename T>
T
lca(typename Tree<T>::List const &list, T p, T q)
{
    auto [elems, root] = Tree<T>::from_list(list);
    size_t found { 0 };
    return get_lca(root, p, q, found).value();
}

int
main()
{
    Tree<int>::List t1 { 6, 2, 8, 0, 4, 7, 9, {}, {}, 3, 5 };

    // 2 8 => 6, 3 7 => 6, 3 5=>4, 7 9=>8
    // 66482
    cout << lca<int>(t1, 2, 8) << lca<int>(t1, 3, 7) << lca<int>(t1, 3, 5)
         << lca<int>(t1, 7, 9) << lca<int>(t1, 2, 5) << "\n";
}
