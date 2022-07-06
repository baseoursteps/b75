#include "tree.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void
_is_bst(typename Tree<T>::Child root, vector<std::reference_wrapper<T>> &vals)
{
    auto locked = root.lock();

    if (!locked)
        return;

    _is_bst(locked->left, vals);
    vals.push_back(locked->val);
    _is_bst(locked->right, vals);
}

template<typename T>
bool
is_bst(typename Tree<T>::List const &l1)
{
    auto [elems, root] = Tree<T>::from_list(l1);
    std::vector<std::reference_wrapper<T>> vals;
    _is_bst(root, vals);
    return std::is_sorted(vals.begin(), vals.end());
}

int
main()
{
    // true
    Tree<int>::List t1 { 2, 1, 3 };

    // false
    Tree<int>::List t2 { 5, 1, 4, {}, {}, 3, 6 };

    // false
    Tree<int>::List t3 { 5, 4, 6, {}, {}, 3, 7 };

    // 100
    cout << is_bst<int>(t1) << is_bst<int>(t2) << is_bst<int>(t3) << "\n";
}
