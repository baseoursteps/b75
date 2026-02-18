#include "list.hpp"

#include <iostream>

using namespace std;

template<typename T>
bool
has_cycle(typename LList<T>::Owned head)
{
    if (!head)
        return false;

    auto i = head;
    auto j = i->getNext().lock();

    while (i && j) {
        if (i == j)
            return true;

        i = i->getNext().lock();
        j = j->getNext().lock();

        if (!j)
            break;
        else
            j = j->getNext().lock();
    }

    return false;
}

int
main()
{
    auto &&[el, head] = LList<int>::from_list({ 1, 2, 3, 4, 5, 6, 7, 8 });

    el.at(7)->getNext() = head;

    cout << has_cycle<int>(head);

    el.at(7)->getNext() = {};

    cout << has_cycle<int>(head);

    cout << "\n";
}
