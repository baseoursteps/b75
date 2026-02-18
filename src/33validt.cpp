#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "graph.h"
#include "matrix.h"

using namespace std;

// Given n nodes labeled from 0 to n — 1 and a list of undirected edges (each
// edge is a pair of nodes), write a function to check whether these edges make
// up a valid tree.

// a valid tree is a connected graph without cycles

bool
dfs(Graph<int>::Owned current, int prev, unordered_set<int> &visited)
{
    if (visited.count(current->val))
        return false;

    visited.insert(current->val);
    for (auto &&n : current->neigh) {
        if (auto l = n.lock()) {
            // TODO I cannot wrap my head around this check!!
            if (l->val == prev)
                continue;

            if (!dfs(l, current->val, visited))
                return false;
        }
    }

    return true;
}

bool
is_tree(unordered_map<int, Graph<int>::Owned> vertex)
{
    if (vertex.empty())
        return false;

    unordered_set<int> visited;
    return dfs(vertex.begin()->second, -1, visited) &&
           visited.size() == vertex.size();
}

int
main()
{
    // matrix<int> edges { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 } }; //yes
    matrix<int> edges { { 0, 1 }, { 2, 0 }, { 3, 0 }, { 1, 4 } }; // yes
    // //no
    // matrix<int> edges { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 4 } };

    unordered_map<int, Graph<int>::Owned> vertex;

    for (auto &&ver : edges) {
        vertex[ver.at(0)] = make_shared<Graph<int>>(ver.at(0));
        vertex[ver.at(1)] = make_shared<Graph<int>>(ver.at(1));
    }

    for (auto &&ver : edges) {
        vertex[ver.at(0)]->neigh.push_back(vertex[ver.at(1)]);
        vertex[ver.at(1)]->neigh.push_back(vertex[ver.at(0)]);
    }

    cout << vertex.begin()->second << "\n";

    cout << (is_tree(vertex) ? "true" : "false") << "\n";
}
