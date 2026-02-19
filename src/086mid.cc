#include <cstddef>
#include <iostream>
#include <vector>

#include "list.hpp"

using namespace std;

// Given the head of a singly linked list, return the middle node of the linked
// list.
//
// If there are two middle nodes, return the second middle node.

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

ListNode *
middleNode(ListNode *head)
{
    ssize_t count {};

    auto it = head;
    while (it) {
        count++;
        it = it->next;
    }

    count /= 2;

    it = head;

    while (count > 0) {
        it = it->next;
        count--;
    }

    return it;
}

int
main()
{
    vector<ListNode> ln { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } };

    for (size_t i = 1; i < ln.size() - 1; ++i)
        ln.at(i - 1).next = &ln.at(i);

    cout << middleNode(&ln.front())->val << "\n";
    ln.at(ln.size() - 2).next = &ln.at(ln.size() - 1);
    cout << middleNode(&ln.front())->val << "\n";
}
