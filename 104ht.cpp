#include <cstddef>
#include <ios>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// A tree is an undirected graph in which any two vertices are connected by
// exactly one path. In other words, any connected graph without simple cycles
// is a tree.
//
// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges
// where edges[i] = [ai, bi] indicates that there is an undirected edge between
// the two nodes ai and bi in the tree, you can choose any node of the tree as
// the root. When you select a node x as the root, the result tree has height h.
// Among all possible rooted trees, those with minimum height (i.e. min(h))  are
// called minimum height trees (MHTs).
//
// Return a list of all MHTs' root labels. You can return the answer in any
// order.
//
// The height of a rooted tree is the number of edges on the longest downward
// path between the root and a leaf.

// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]

// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]

int
dfs(int                        n,
    const vector<vector<int>> &adj,
    unordered_set<int>        &visited,
    int                        depth,
    int                        min)
{
    if (visited.count(n))
        return 0;
    else if (depth > min)
        return min + 1;
    else {
        visited.insert(n);
        int nd = depth;
        for (auto next : adj.at(n)) {
            nd = max(nd, dfs(next, adj, visited, depth + 1, min));
            if (nd > min)
                break;
        }

        return nd;
    }
}

vector<int>
findMinHeightTreesShit(int n, vector<vector<int>> &edges)
{
    // adj list
    vector<vector<int>> adj(n + 1, vector<int>());

    for (auto &&edge : edges) {
        adj.at(edge.at(0)).push_back(edge.at(1));
        adj.at(edge.at(1)).push_back(edge.at(0));
    }

    int         min { n };
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        unordered_set<int> visited;
        auto               h = dfs(i, adj, visited, 0, min);

        if (h < min) {
            sol.clear();
            sol.push_back(i);
            min = h;
        } else if (h == min)
            sol.push_back(i);
    }

    return sol;
}

// interesting. basically a topo sort where you start from the leaves and prune
// them as long as there are more than two nodes. the nodes in the middle of the
// cloud (let's say) have the shortest path to the limit of the cloud
vector<int>
findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
        return { 0 };

    vector<unordered_set<int>> adj { size_t(n + 1) };

    for (auto &&edge : edges) {
        adj.at(edge.at(0)).insert(edge.at(1));
        adj.at(edge.at(1)).insert(edge.at(0));
    }

    vector<int> leaves;

    for (size_t i = 0; i < adj.size(); ++i)
        if (adj.at(i).size() == 1)
            leaves.push_back(i);

    while (n > 2) {
        n -= leaves.size();

        vector<int> newLeaves;

        for (auto leaf : leaves) {
            auto j = *adj.at(leaf).begin();
            adj.at(j).erase(leaf);
            if (adj.at(j).size() == 1)
                newLeaves.push_back(j);
        }
        leaves = move(newLeaves);
    }

    return leaves;
}

void
sol(int n, vector<vector<int>> edgy)
{
    for (auto &&i : findMinHeightTrees(n, edgy))
        cout << i << " ";

    cout << "\n";
}

int
main()
{
    // Input: n = 4, edges = [[1,0],[1,2],[1,3]]
    // Output: [1]

    // Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
    // Output: [3,4]

    sol(4, { { 1, 0 }, { 1, 2 }, { 1, 3 } });
    sol(6, { { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 4 }, { 5, 4 } });
}
