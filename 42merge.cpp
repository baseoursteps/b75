#include "list.hpp"

#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
typename LList<T>::Owned
merge(typename LList<T>::Owned h1, typename LList<T>::Owned h2)
{
    if (!(h1 || h2))
        return {};

    if (!h1)
        return h2;

    if (!h2)
        return h1;

    typename LList<T>::Owned ret, it;

    if (h1->getVal() <= h2->getVal()) {
        ret = it = h1;
        h1       = h1->getNext().lock();
    } else {
        ret = it = h2;
        h2       = h2->getNext().lock();
    }

    while (h1 && h2) {
        if (h1->getVal() <= h2->getVal()) {
            it->getNext() = h1;
            it            = it->getNext().lock();
            h1            = h1->getNext().lock();
        } else {
            it->getNext() = h2;
            it            = it->getNext().lock();
            h2            = h2->getNext().lock();
        }
    }

    while (h1) {
        it->getNext() = h1;
        h1            = h1->getNext().lock();
        it            = it->getNext().lock();
    }

    while (h2) {
        it->getNext() = h2;
        h2            = h2->getNext().lock();
        it            = it->getNext().lock();
    }

    return ret;
}

int
main()
{
    auto [el1, h1] = LList<int>::from_list({ 1, 2, 3, 4, 5 });
    auto [el2, h2] = LList<int>::from_list({ 1, 1, 4, 4, 6, 7, 8 });

    auto h3 = merge<int>(h1, h2);

    cout << h3 << "\n";
    cout << h2 << "\n";
    cout << h1 << "\n";
}
