#include "list.hpp"

#include <queue>

using namespace std;

struct Comparator
{
    bool
    operator()(auto &&a, auto &&b)
    {
        return a->val > b->val;
    }
};

ListNode *
mergeKLists(vector<ListNode *> &lists)
{
    ListNode  phony { -1 };
    ListNode *iterator = &phony;

    priority_queue<ListNode *, vector<ListNode *>, Comparator> pq;

    bool hasElems { true };

    while (hasElems) {
        hasElems = false;
        for (auto &it : lists) {
            if (it) {
                hasElems = true;
                pq.push(it);
                it = (it)->next;
            }
        }
    }

    while (pq.size()) {
        auto it        = pq.top();
        iterator->next = it;
        iterator       = it;
        pq.pop();
    }

    iterator->next = nullptr;

    return phony.next;
}

int
main()
{
}
