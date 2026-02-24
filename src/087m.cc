#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// Given an m x n binary matrix mat, return the distance of the nearest 0 for
// each cell.
//
// The distance between two adjacent cells is 1.

// first add 0 cells to queue, and mark the others as unvisited(-1)
// then do BFS and add 1 to each valid neighbour, then add neighbours to queue

using table = vector<vector<int>>;

bool
isValid(int x, int y, const table &mat)
{
    return x >= 0 && x < mat.size() && y >= 0 && y < mat[x].size();
}

vector<pair<int, int>>
neighs(int x, int y, const table &mat)
{
    vector<pair<int, int>> res { { x + 1, y },
                                 { x - 1, y },
                                 { x, y + 1 },
                                 { x, y - 1 }

    };

    res.erase(std::remove_if(res.begin(),
                             res.end(),
                             [&](auto it) {
                                 return !isValid(it.first, it.second, mat);
                             }),
              res.end());

    return res;
}

vector<vector<int>>
updateMatrix(vector<vector<int>> &mat)
{
    queue<pair<int, int>> q;

    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            if (!mat[i][j]) {
                q.push({ i, j });
            } else {
                mat[i][j] = -1;
            }
        }
    }

    while (q.size()) {
        auto el = q.front();
        q.pop();

        const auto [x, y] = el;
        const auto val    = mat[x][y];

        for (auto n : neighs(x, y, mat)) {
            const auto [nx, ny] = n;
            if (mat[nx][ny] == -1) {
                mat[nx][ny] = val + 1;
                q.push({ nx, ny });
            }
        }
    }

    return mat;
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
