#include "list.hpp"

#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
ssize_t
del(typename LList<T>::Owned  prev,
    typename LList<T>::Owned &next,
    const size_t              kth)
{
    if (!next)
        return -1;

    auto n = next->getNext().lock();

    // last element
    if (!n) {
        if (!kth) {
            next.reset();
            if (prev)
                prev->getNext() = {};
            return -1;
        } else
            return 1;
    } else {
        auto count = del<int>(next, n, kth);
        if (count < 0)
            return -1;
        else if ((size_t)count == kth) {
            next.reset();
            if (prev)
                prev->getNext() = n;
            else
                next = n;

            return -1;
        } else
            return 1 + count;
    }
}

int
main()
{
    auto &&[el, head] = LList<int>::from_list({ 1, 3, 5, 6, 7, 9, 12 });

    del<int>({}, head, 0);
    cout << head << "\n";
}
