#include <array>
#include <cstddef>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

// Given an m x n binary matrix mat, return the distance of the nearest 0 for
// each cell.
//
// The distance between two adjacent cells is 1.

// first add 0 cells to queue, and mark the others as unvisited(-1)
// then do BFS and add 1 to each valid neighbour, then add neighbours to queue
vector<vector<int>>
updateMatrix(vector<vector<int>> &vals)
{
    const array<ssize_t, 4> X_DIR { 1, 0, -1, 0 }, Y_DIR { 0, 1, 0, -1 };
    queue<tuple<int, int>>  q;

    for (size_t i = 0; i < vals.size(); ++i)
        for (size_t j = 0; j < vals.front().size(); ++j)
            if (!vals.at(i).at(j))
                q.emplace(i, j);
            else
                vals.at(i).at(j) = -1;

    while (q.size()) {
        auto [qi, qj] = q.front();
        q.pop();

        for (size_t i = 0; i < X_DIR.size(); ++i) {
            auto ni = qi + X_DIR.at(i);
            auto nj = qj + Y_DIR.at(i);

            if (ni < 0 || nj < 0 || ni >= int(vals.size()) ||
                nj >= int(vals.front().size()) || vals.at(ni).at(nj) != -1)
                continue;
            else {
                vals.at(ni).at(nj) = vals.at(qi).at(qj) + 1;
                q.emplace(ni, nj);
            }
        }
    }

    return vals;
}

int
main()
{
    vector<vector<int>> vals { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } };
    auto              &&sol = updateMatrix(vals);

    for (auto &&l : sol) {
        for (auto &&c : l)
            cout << c << " ";

        cout << "\n";
    }
    cout << "\n";

    // for (auto &&l : vals) {
    //     for (auto &&c : l)
    //         cout << c << " ";
    //
    //     cout << "\n";
    // }
}
