#include <iostream>

#include "tree.h"

using namespace std;

template<typename T>
bool
is_it_tho(typename Tree<T>::Child const &r1u,
          typename Tree<T>::Child const &r2u)
{
    auto r1 = r1u.lock(), r2 = r2u.lock();

    if (!(r1 || r2))
        return true;

    if (r1 && r2) {
        if (r1->val == r2->val)
            return is_it_tho<T>(r1->left, r2->left) &&
                   is_it_tho<T>(r1->right, r2->right);
        else
            return is_it_tho<T>(r1->left, r2) || is_it_tho<T>(r1->right, r2);
    }

    return false;
}

template<typename T>
bool
is_subtree(typename Tree<T>::List const &t1, typename Tree<T>::List const &t2)
{
    auto [elems1, root1] = Tree<T>::from_list(t1);
    auto [elems2, root2] = Tree<T>::from_list(t2);
    return is_it_tho<T>(root1, root2);
}

int
main()
{
    // yes
    Tree<int>::List t1 { 1, 2, 3, {}, 4, {}, {} }, t2 { 2, {}, 4 };
    // yes
    Tree<int>::List t3 { 3, 4, 5, 1, 2 }, t4 { 4, 1, 2 };
    // no
    Tree<int>::List t5 { 3, 4, 5, 1, 2, {}, {}, {}, {}, 0 }, t6 { 4, 1, 2 };

    // 110
    cout << is_subtree<int>(t1, t2) << is_subtree<int>(t3, t4)
         << is_subtree<int>(t5, t6) << "\n";
}
