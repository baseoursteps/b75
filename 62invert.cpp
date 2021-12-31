#include <iostream>
#include <tuple>

#include "tree.h"

using namespace std;

template<typename T>
void
rotate(typename Tree<T>::Child r)
{
    auto locked = r.lock();
    if (!locked)
        return;

    swap(locked->left, locked->right);
    rotate<T>(locked->left);
    rotate<T>(locked->right);
}

template<typename T>
void
flip(const typename Tree<T>::List &l)
{
    typename Tree<T>::OwnedTree root;
    auto                        elems = Tree<T>::from_list(l, root);

    cout << root << "\n";
    rotate<T>(root);
    cout << root << "\n";
}

int
main()
{
    Tree<int>::List l1 { 4, 2, 7, 1, 3, 6, 9 }, rez1 { 4, 7, 2, 9, 6, 3, 1 };
    Tree<int>::List l2 { 2, 1, 3 }, rez2 { 2, 3, 1 };
    Tree<int>::List l3 {}, rez3 {};

    flip<int>(l1);
    flip<int>(l2);
    flip<int>(l3);
}
