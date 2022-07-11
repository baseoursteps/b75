#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to
// first take course 1.
//
// Return true if you can finish all courses. Otherwise, return false.
//
//
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
//
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you
// should also have finished course 1. So it is impossible.

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.
bool
canFinish(int numCourses, const vector<vector<int>> &prerequisites)
{
    vector<vector<int>> deps(numCourses, vector<int>());

    for (auto &&e : prerequisites)
        deps.at(e.at(1)).push_back(e.at(0));

    for (int curr = 0; curr < numCourses; ++curr) {
        vector<int> vals;
        vals.push_back(curr);
        unordered_set<int> seen;
        while (vals.size()) {
            int v = vals.back();
            vals.pop_back();
            seen.insert(v);

            for (auto &&i : deps.at(v)) {
                if (i == curr)
                    return false;

                if (!seen.count(i))
                    vals.push_back(i);
            }
        }
    }
    return true;
}

// TODO Kahn's algo

int
main()
{
    // true
    cout << canFinish(5, { { 1, 4 }, { 2, 4 }, { 3, 1 }, { 3, 2 } }) << "\n\n";
    // false
    cout << canFinish(4, { { 0, 1 }, { 3, 1 }, { 1, 3 }, { 3, 2 } }) << "\n\n";
    // true
    cout << canFinish(
        8,
        { { 1, 0 }, { 2, 6 }, { 1, 7 }, { 6, 4 }, { 7, 0 }, { 0, 5 } });
    cout << "\n\n";
}
