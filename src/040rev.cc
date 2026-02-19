#include "list.hpp"

ListNode *
rev(ListNode *prev, ListNode *current)
{
    if (!current) {
        return prev;
    }

    auto n        = current->next;
    current->next = prev;

    return rev(current, n);
}

ListNode *
reverseList(ListNode *head)
{
    return rev({}, head);
}

int
main()
{
}
