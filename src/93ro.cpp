#include <array>
#include <cstddef>
#include <iostream>
#include <queue>
#include <sys/types.h>
#include <vector>

using namespace std;

// You are given an m x n grid where each cell can have one of three values:
//
//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.
//
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten
// orange becomes rotten.
//
// Return the minimum number of minutes that must elapse until no cell has a
// fresh orange. If this is impossible, return -1.
//
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
//
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never
// rotten, because rotting only happens 4-directionally.
//
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer
// is just 0.

// still some kind of BFS
int
orangesRotting(vector<vector<int>> &grid)
{
    queue<array<ssize_t, 2>> pos;
    array<ssize_t, 4>        X_DIR { 1, 0, -1, 0 }, Y_DIR { 0, 1, 0, -1 };

    int fresh {};
    for (size_t i = 0; i < grid.size(); ++i)
        for (size_t j = 0; j < grid.at(i).size(); ++j)
            if (grid.at(i).at(j) == 2)
                pos.push({ ssize_t(i), ssize_t(j) });
            else if (grid.at(i).at(j) == 1)
                fresh++;

    int count { -2 };
    while (!pos.empty()) {
        queue<array<ssize_t, 2>> next = move(pos);

        while (!next.empty()) {
            auto v = next.front();
            next.pop();

            const auto x = v.front(), y = v.back();
            if (x < 0 || x >= ssize_t(grid.size()) || y < 0 ||
                y >= ssize_t(grid.front().size()))
                continue;

            auto &orange = grid.at(x).at(y);

            if (orange == 0)
                continue;
            else if (orange == 1)
                fresh--;

            orange = 0;

            for (size_t i = 0; i < X_DIR.size(); ++i) {
                const auto n_x = x + X_DIR.at(i), n_y = y + Y_DIR.at(i);
                pos.push({ n_x, n_y });
            }
        }

        count++;
    }

    if (fresh > 0)
        return -1;
    else if (count > 0)
        return count;
    else
        return 0;
}

int
main()
{
    vector<vector<int>> g1 { { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } },
        g2 { { 2, 1, 1 }, { 0, 1, 1 }, { 1, 0, 1 } }, g3 { { 0, 2 } };
    cout << orangesRotting(g1) << orangesRotting(g2) << orangesRotting(g3);

    cout << "\n";
}
