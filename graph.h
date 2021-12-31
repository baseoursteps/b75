#pragma once

#include <array>
#include <cstddef>
#include <deque>
#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template<typename T>
struct Graph
{
    using Neigh = std::vector<std::weak_ptr<Graph<T>>>;
    using Owned = std::shared_ptr<Graph<T>>;
    using Edges = std::vector<std::array<T, 2>>;

    T     val;
    Neigh neigh;

    Graph<T>() : val { {} } {}
    Graph<T>(const T &val) : val(val) {}
    Graph<T>(const T &val, const Neigh &neigh) : val(val), neigh(neigh) {}

    static std::unordered_map<T, typename Graph<T>::Owned>
    from_edges(const Graph<T>::Edges &edges, bool directed = false)
    {
        std::unordered_map<T, Graph<T>::Owned> elems;

        for (auto &&e : edges) {
            elems.insert({ e.at(0), std::make_shared<Graph<T>>(e.at(0)) });
            elems.insert({ e.at(1), std::make_shared<Graph<T>>(e.at(1)) });
        }

        for (auto &&e : edges) {
            elems.at(e.at(0))->neigh.push_back(elems.at(e.at(1)));
            if (!directed)
                elems.at(e.at(1))->neigh.push_back(elems.at(e.at(0)));
        }

        return elems;
    }

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

            if (!visited.count(c))
                continue;

            visited.insert(c);

            out << "\nval: " << c->val << ", neighs:";

            for (auto &&n : c->neigh) {
                if (auto nl = n.lock()) {
                    out << nl->val << " ";

                    if (!visited.count(nl))
                        all.push_back(nl);
                }
            }
        }

        return out;
    }
};
