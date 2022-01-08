#include "heap.hpp"
#include "list.hpp"

#include <iostream>
#include <vector>

using namespace std;

// You are given an array of k linked-lists lists, each linked-list is sorted in
// ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// use a binary heap to always get the next element
// initially add all heads to bheap
// keep a global head(head) and global last(tail) to track head and tail of
// merged list

// pop from heap -- update head if required, update last->next otherwise

// set tail to popped

// add tail->next back to heap

// reset tail->next

// repeat while we have elements in the heap

// elegant i like it

int
main()
{
    auto [e1, l1] = LList<int>::from_list({ 1, 4, 5 });
    auto [e2, l2] = LList<int>::from_list({ 1, 3, 4 });
    auto [e3, l3] = LList<int>::from_list({ 2, 6 });

    Heap<LList<int>::Owned, Type::Min> heap;

    heap.insert(l1);
    heap.insert(l2);
    heap.insert(l3);

    LList<int>::Owned head, last;

    while (!heap.empty()) {
        auto current = heap.pop_front().value();

        if (!head)
            head = current;
        else
            last->getNext() = current;

        last = current;

        auto next = last->getNext().lock();
        if (next)
            heap.insert(next);

        last->getNext() = {};
    }

    cout << head << "\n";
}
