#include "graph.h"

#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_set>
#include <vector>

using namespace std;

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//     For example, the pair [0, 1], indicates that to take course 0 you have to
//     first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// i think the idea is to map the courses as a directed graph
// given any node we should NOT be able to reach it again ?

// map neighbours are following courses

// the solution is O(n^²), is there a better one?

// !!
// the optimal solution is to do a modified DFS which accounts for visited and
// partially visited elements. an element is marked as visited if while going
// through all its possible connections we reach an end without meeting itself
// on the way. a node is marked as partially visited before calling dfs on its
// neighbours.

// [a b] - a depends on b
using prereq = vector<vector<int>>;

bool
can_finish(const prereq &preqs)
{
    map<int, shared_ptr<Graph<int>>> vals;

    // build graph
    for (auto &&p : preqs) {
        if (vals.find(p.at(1)) == vals.end())
            vals.insert({ p.at(1), std::make_shared<Graph<int>>(p.at(1)) });

        if (vals.find(p.at(0)) == vals.end())
            vals.insert({ p.at(0), std::make_shared<Graph<int>>(p.at(0)) });

        vals.at(p.at(1))->neigh.push_back(vals.at(p.at(0)));
    }

    // std::cout << vals.begin()->second << "\n";
    map<shared_ptr<Graph<int>>, unordered_set<shared_ptr<Graph<int>>>>
        traversed;
    for (auto &&k : vals) {
        auto id = k.first;

        // get a list of all reachables
        deque<shared_ptr<Graph<int>>>         all;
        unordered_set<shared_ptr<Graph<int>>> visited;

        all.push_back(k.second);

        while (!all.empty()) {
            auto curr = all.front();
            all.pop_front();

            if (visited.find(curr) != visited.end())
                continue;

            visited.insert(curr);

            for (auto &&neigh : curr->neigh) {
                auto locked = neigh.lock();
                // if any of the following nodes is identical to the first --
                // quit
                if (locked->val == id)
                    return false;
                all.push_back(locked);
            }
        }
    }

    return true;
}

bool
visit(map<shared_ptr<Graph<int>>, bool> &marks,
      const shared_ptr<Graph<int>>      &node)
{
    auto current = marks.find(node);

    // if the node has already been visted succesfully
    if (current == marks.end())
        return true;

    // if while visiting we stumble upon a predecessor -- we have a loop
    if (current->second)
        return false;

    current->second = true;

    for (auto &n : node->neigh) {
        if (!visit(marks, n.lock()))
            return false;
    }

    // only after going through all the possible neighbours do we mark as
    // visited
    marks.erase(node);

    return true;
}

bool
can_finish_dfs(const prereq &preqs)
{
    map<int, shared_ptr<Graph<int>>> vals;

    // build graph
    for (auto &&p : preqs) {
        auto former = p.at(1);
        auto latter = p.at(0);

        if (vals.find(former) == vals.end())
            vals.insert({ former, std::make_shared<Graph<int>>(former) });

        if (vals.find(latter) == vals.end())
            vals.insert({ latter, std::make_shared<Graph<int>>(latter) });

        vals.at(former)->neigh.push_back(vals.at(latter));
    }

    map<shared_ptr<Graph<int>>, bool> marks;

    for (auto &&[_, v] : vals)
        marks.insert({ v, false });

    while (!marks.empty()) {
        auto elem = marks.begin();
        if (!visit(marks, elem->first))
            return false;
    }

    return true;
}

int
main()
{
    prereq a { { 0, 1 }, { 1, 0 } };
    prereq b { { 0, 1 } };
    prereq c { { 1, 0 }, { 2, 1 }, { 3, 1 }, { 4, 3 }, { 3, 2 }, { 5, 4 } };

    cout << can_finish(a) << " " << can_finish(b) << " " << can_finish(c) << " "
         << "\n";

    cout << can_finish_dfs(a) << " " << can_finish_dfs(b) << " "
         << can_finish_dfs(c) << " "
         << "\n";
}
