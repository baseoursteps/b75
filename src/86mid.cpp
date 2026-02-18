#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given the head of a singly linked list, return the middle node of the linked
// list.
//
// If there are two middle nodes, return the second middle node.

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

struct ListNode
{
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *
middleNode(ListNode *head)
{
    size_t count = 0;
    for (auto i = head; i != nullptr; i = i->next, count++) {
    }

    count /= 2;

    for (size_t i = 0; i < count; ++i)
        head = head->next;

    return head;
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
