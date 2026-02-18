#include <iostream>

using namespace std;

struct Node
{
    int   val;
    Node *next {};

    Node(int v) : val(v) {}
};

Node *
rev(Node *prev, Node *current, Node *end)
{
    if (!current || current == end) {
        return prev;
    } else {
        auto n { current->next };
        current->next = prev;
        return rev(current, n, end);
    }
}

Node *
reverse(Node *head, size_t start, size_t end)
{
    if (start >= end)
        return head;

    auto rev_start { head }, rev_end { head };

    for (size_t i = 1; i < start && rev_start; ++i)
        rev_start = rev_start->next;

    for (size_t i = 0; i < end && rev_end; ++i)
        rev_end = rev_end->next;

    if (!rev_start)
        return head;

    auto n_start = rev(rev_end, rev_start, rev_end);

    auto i { head };
    while (i != rev_start && i->next != rev_start)
        i = i->next;

    if (i != rev_start)
        i->next = n_start;
    else
        head = n_start;

    return head;
}

int
main()
{
    Node *head {};

    for (auto i = 100; i > 0; --i) {
        auto n  = new Node { i };
        n->next = head;
        head    = n;
    }

    head = reverse(head, 2, 99);

    for (auto i = head; i; i = i->next) {
        cout << i->val << " ";
    }

    cout << "\n";
}
