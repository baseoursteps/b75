#include "list.hpp"

#include <iostream>

using namespace std;

template<typename T>
typename LList<T>::Owned
reorder(typename LList<T>::Owned head, typename LList<T>::Owned next)
{
    if (!(head && next))
        return {};

    if (!next->getNext().lock()) {
        auto n = head->getNext().lock();
        if (n != next) {
            head->getNext() = next;
            next->getNext() = n;
            return n;
        } else // only two elements
            return {};
    } else {
        head = reorder<T>(head, next->getNext().lock());
        if (!head)
            return {};
        else if (head == next || head->getNext().lock() == next) {
            next->getNext() = {};
            return {};
        } else {
            auto n          = head->getNext().lock();
            head->getNext() = next;
            next->getNext() = n;
            return n;
        }
    }
}

int
main()
{
    auto [el, h] = LList<int>::from_list({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    // auto [el, h] = LList<int>::from_list({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    // auto [el, h] = LList<int>::from_list({ 0, 1 });

    reorder<int>(h, h->getNext().lock());
    cout << h << "\n";
}
