#include <iostream>
#include <vector>

using namespace std;

// You are climbing a staircase. It takes n steps to reach the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

int
climb(int n, vector<int> &vals)
{
    if (n < 1)
        return 1;
    else if (vals.at(n) != -1)
        return vals.at(n);
    else
        vals.at(n) = climb(n - 1, vals) + climb(n - 2, vals);

    return vals.at(n);
}

int
climbStairs(int n)
{
    vector<int> vals(n + 1, -1);
    vals.at(1) = 1;
    vals.at(2) = 2;

    return climb(n, vals);
}

int
main()
{
    cout << climbStairs(3) << " " << climbStairs(2) << " " << climbStairs(47);

    cout << "\n";
}
