#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// There is a robot on an m x n grid. The robot is initially located at the
// top-left corner (i.e., grid[0][0]). The robot tries to move to the
// bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
// either down or right at any point in time.
//
// Given the two integers m and n, return the number of possible unique paths
// that the robot can take to reach the bottom-right corner.
//
// The test cases are generated so that the answer will be less than or equal to
// 2 * 109.
//
// Input: m = 3, n = 7
// Output: 28

int
uniquePaths(int m, int n)
{
    vector<vector<int>> sol(m, vector<int>(n, -1));
    sol.at(0) = vector<int>(n, 1);

    for (int i = 0; i < m; ++i)
        sol.at(i).front() = 1;

    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            sol.at(i).at(j) = sol.at(i).at(j - 1) + sol.at(i - 1).at(j);

    return sol.at(m - 1).at(n - 1);
}

int
main()
{
    cout << uniquePaths(3, 7) << "\n";
}
