#include <iostream>
#include <unordered_map>

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

unordered_map<int, int> sol { { 0, 0 }, { 2, 2 }, { 1, 1 } };
int
climbStairs(int n)
{
    if (n <= 0) {
        return 0;
    } else if (sol.count(n)) {
        return sol.at(n);
    } else {
        sol[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return sol[n];
    }
}

int
main()
{
    cout << climbStairs(3) << " " << climbStairs(2) << " " << climbStairs(47);

    cout << "\n";
}
