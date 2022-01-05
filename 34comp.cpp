#include <array>
#include <cstddef>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "graph.h"

using namespace std;

// given a list of edges in an undirected graph count the connected components

using edge = array<size_t, 2>;

// we need a sort of dfs where we mark elements as we visit them
// after we visit them and we still have unvisited it means that we start a new
// component

template<typename T>
void
dfs(T elem, unordered_map<T, typename Graph<T>::Owned> &vals)
{
    if (!vals.count(elem))
        return;

    auto neigh = std::move(vals.at(elem)->neigh);
    vals.erase(elem);

    for (auto &&n : neigh)
        if (auto l = n.lock())
            dfs(l->val, vals);
}

template<typename T>
size_t
count_comp(typename Graph<T>::Edges const &edges)
{
    T count {};

    auto vals = Graph<T>::from_edges(edges);

    while (!vals.empty()) {
        auto elem = vals.begin();
        count++;
        dfs(elem->second->val, vals);
    }

    return count;
}

int
main()
{
    // 2 components
    Graph<size_t>::Edges edges0 { { 0, 1 }, { 1, 2 }, { 3, 4 } };

    // 1
    Graph<size_t>::Edges edges1 { { 0, 1 }, { 1, 2 }, { 3, 2 } };

    // 3
    Graph<size_t>::Edges edges2 { { 0, 1 }, { 1, 0 }, { 2, 1 },
                                  { 0, 2 }, { 3, 4 }, { 5, 6 } };

    cout << count_comp<size_t>(edges0) << count_comp<size_t>(edges1)
         << count_comp<size_t>(edges2) << "\n";
}
