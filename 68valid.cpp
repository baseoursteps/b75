#include <iostream>

#include "tree.h"

using namespace std;

template<typename T>
bool
_is_bst(typename Tree<T>::Child root)
{
    auto locked = root.lock();

    if (!locked)
        return true;

    auto ok { true };
    if (auto llock = locked->left.lock())
        ok &= locked->val > llock->val;

    if (auto rlock = locked->right.lock())
        ok &= locked->val < rlock->val;

    return ok && _is_bst<T>(locked->left) && _is_bst<T>(locked->right);
}

template<typename T>
bool
is_bst(typename Tree<T>::List const &l1)
{
    auto [elems, root] = Tree<T>::from_list(l1);
    return _is_bst<T>(root);
}

int
main()
{
    // true
    Tree<int>::List t1 { 2, 1, 3 };

    // false
    Tree<int>::List t2 { 5, 1, 4, {}, {}, 3, 6 };

    // 10
    cout << is_bst<int>(t1) << is_bst<int>(t2) << "\n";
}
