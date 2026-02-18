#include "list.hpp"

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// also present in heap section
// now we use stl's priority queue

template<>
struct std::greater<LList<int>::Owned>
{
    bool
    operator()(const LList<int>::Owned &lhs, const LList<int>::Owned &rhs) const
    {
        return lhs->getVal() > rhs->getVal();
    }
};

int
main()
{
    auto [e1, h1] = LList<int>::from_list({ 1, 2, 3, 4, 5, 6, 7 });
    auto [e2, h2] = LList<int>::from_list({ 1, 2, 3, 4, 5, 6, 7 });
    auto [e3, h3] =
        LList<int>::from_list({ 5, 5, 5, 6, 6, 6, 7, 7, 8, 10, 11, 23 });

    priority_queue<LList<int>::Owned,
                   vector<LList<int>::Owned>,
                   greater<LList<int>::Owned>>
        q;

    q.push(h1);
    q.push(h2);
    q.push(h3);

    LList<int>::Owned rez, it;
    while (!q.empty()) {
        auto n = q.top();
        q.pop();

        if (!rez)
            rez = it = n;
        else {
            it->getNext() = n;
            it            = it->getNext().lock();
        }

        auto next = n->getNext().lock();
        if (next)
            q.push(next);
    }

    cout << rez << "\n";
}
