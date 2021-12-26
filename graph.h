#pragma once

#include <deque>
#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_set>
#include <vector>

// TODO -- break cycle in order to permit graph to deallocate
template<typename T>
struct Graph
{
    using Neigh = std::vector<std::weak_ptr<Graph<T>>>;
    using Owned = std::shared_ptr<Graph<T>>;

    T     val;
    Neigh neigh;

    Graph<T>() : val { {} } {}
    Graph<T>(const T &val) : val(val) {}
    Graph<T>(const T &val, const Neigh &neigh) : val(val), neigh(neigh) {}

    friend std::ostream &
    operator<<(std::ostream &out, Owned &g)
    {
        if (!g)
            return out;

        std::unordered_set<Owned> visited;
        std::deque<Owned>         all;

        all.push_back(g);

        while (!all.empty()) {
            auto c = all.front();
            all.pop_front();

            if (visited.find(c) != visited.end())
                continue;

            visited.insert(c);

            out << "\nval: " << c->val << ", neighs:";

            for (auto &&n : c->neigh) {
                if (auto nl = n.lock()) {
                    out << nl->val << " ";

                    if (visited.find(nl) == visited.end())
                        all.push_back(nl);
                }
            }
        }

        return out;
    }
};
