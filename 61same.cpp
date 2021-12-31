#include <iostream>

#include "tree.h"

using namespace std;

// Given the roots of two binary trees p and q, write a function to check if
// they are the same or not. Two binary trees are considered the same if they
// are structurally identical, and the nodes have the same value.

template<typename T>
bool
are_same(typename Tree<T>::Child root1, typename Tree<T>::Child root2)
{
    auto l1 = root1.lock(), l2 = root2.lock();

    if (!(l1 || l2))
        return true;

    if (l1 && l2)
        if (l1->val == l2->val)
            return are_same<T>(l1->left, l2->left) &&
                   are_same<T>(l1->right, l2->right);

    return false;
}

template<typename T>
bool
same_trees(const typename Tree<T>::List &list1,
           const typename Tree<T>::List &list2)
{
    typename Tree<T>::OwnedTree root1, root2;

    auto elems1 = Tree<T>::from_list(list1, root1),
         elems2 = Tree<T>::from_list(list2, root2);

    return are_same<T>(root1, root2);
}

int
main()
{
    // 1
    Tree<int>::List t0 { 1, 2, 3 }, t1 { 1, 2, 3 };

    // 0
    Tree<int>::List t2 { 1, 2 }, t3 { 1, {}, 2 };

    cout << same_trees<int>(t0, t1) << same_trees<int>(t2, t3) << "\n";
}
