#include "list.hpp"

bool
hasCycle(ListNode *head)
{
    if (!head) {
        return false;
    }

    auto fast = head->next;
    if (!fast) {
        return false;
    }

    fast = head->next;

    while (head && fast) {
        if (fast == head) {
            return true;
        }

        head = head->next;

        fast = fast->next;
        if (!fast) {
            return false;
        }
        fast = fast->next;
    }

    return false;
}

int
main()
{
}
