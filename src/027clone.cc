#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "graph.h"
// given a node in an undirected graph, deep clone the graph

using namespace std;

class Solution
{
public:
    Node *
    cloneGraph(Node *node)
    {
        if (!node) {
            return {};
        }

        unordered_set<Node *>         visited;
        unordered_map<Node *, Node *> clones;
        queue<Node *>                 q;

        q.push(node);

        // first clone all
        while (q.size()) {
            auto el = q.front();
            q.pop();

            if (visited.count(el)) {
                continue;
            } else {
                visited.insert(el);
            }

            Node *n = new Node;
            n->val  = el->val;

            clones[el] = n;

            for (auto &&neigh : el->neighbors) {
                q.push(neigh);
            }
        }

        visited.clear();
        auto new_head = clones.at(node);
        q.push(node);

        // then update clone adjacency
        while (q.size()) {
            auto el = q.front();
            q.pop();

            if (visited.count(el)) {
                continue;
            } else {
                visited.insert(el);
            }

            auto clone = clones.at(el);

            for (auto &&neigh : el->neighbors) {
                clone->neighbors.push_back(clones.at(neigh));
                q.push(neigh);
            }
        }

        return new_head;
    }
};

int
main()
{
}
