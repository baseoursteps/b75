#include "list.hpp"

#include <iostream>

using namespace std;

template<typename T>
typename LList<T>::Owned
rev(typename LList<T>::Owned current, typename LList<T>::Owned next)
{
    if (!next)
        return current;

    auto n          = next->getNext();
    next->getNext() = current;

    return rev<T>(next, n.lock());
}

int
main()
{
    auto &&[em, head] = LList<int>::from_list({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

    head = rev<int>({}, head);
    cout << head << "\n";
    head = rev<int>({}, head);
    cout << head << "\n";
}
