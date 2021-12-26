#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "graph.h"
// given a node in an undirected graph, deep clone the graph

using namespace std;

template<typename T>
void
pop_map(shared_ptr<Graph<T>>                                       node,
        unordered_map<shared_ptr<Graph<T>>, shared_ptr<Graph<T>>> &vals)
{
    if (!node)
        return;

    if (vals.find(node) == vals.end()) {
        vals.insert({ node, {} });
        for (auto &&i : node->neigh) {
            pop_map(i.lock(), vals);
        }
    }
}

// we need to return a vector instead of just an element because otherwise the
// only shared_ptr of the actual nodes would go out of scope with this function
// -- the unordered map vals
template<typename T>
vector<typename Graph<T>::Owned>
deep(shared_ptr<Graph<T>> &node)
{
    if (!node)
        return {};

    unordered_map<shared_ptr<Graph<T>>, shared_ptr<Graph<T>>> vals;

    pop_map(node, vals);

    vector<typename Graph<T>::Owned> vec;

    // first create the nodes
    for (auto &&[k, v] : vals) {
        v = std::make_shared<Graph<T>>(k->val);
        vec.push_back(v);
    }

    // then update adj_list
    for (auto &&[k, v] : vals) {
        for (auto nei : k->neigh) {
            auto new_neigh = vals.at(nei.lock());
            v->neigh.push_back(new_neigh);
        }
    }

    return vec;
}

int
main()
{
    auto a = std::make_shared<Graph<int>>(1);
    auto b = std::make_shared<Graph<int>>(2);
    auto c = std::make_shared<Graph<int>>(3);
    auto d = std::make_shared<Graph<int>>(4);

    vector<weak_ptr<Graph<int>>> al { b, d }, bl { a, c }, cl { d, b },
        dl { c, a };

    a->neigh = al;
    b->neigh = bl;
    c->neigh = cl;
    d->neigh = dl;

    cout << a << "\n--";

    auto cloned = deep(b);

    cout << cloned.front() << "\n";
}
