#include <cstddef>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an array of distinct integers nums and a target integer target, return
// the number of possible combinations that add up to target.
//
// The test cases are generated so that the answer can fit in a 32-bit integer.

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
// Note that different sequences are counted as different combinations.

// Follow up: What if negative numbers are allowed in the given array? How does
// it change the problem? What limitation we need to add to the question to
// allow negative numbers?

int
findDFS(int target, const vector<int> &vals)
{
    if (!target)
        return 1;

    int sum {};

    for (auto &&val : vals)
        if (val <= target)
            sum += findDFS(target - val, vals);

    return sum;
}

int
findTD(int target, vector<int> &sol, const vector<int> &vals)
{
    if (sol.at(target) > 0)
        return sol.at(target);

    int sum {};
    for (auto &&v : vals)
        if (v <= target)
            sum += findTD(target - v, sol, vals);

    sol.at(target) = sum;

    return sum;
}

int
findBU(int target, vector<int> &sol, const vector<int> &vals)
{
    for (int i = 1; i <= target; ++i)
        for (auto &&v : vals)
            if (v <= i)
                sol.at(i) += sol.at(i - v);

    return sol.at(target);
}

int
sol(int target, const vector<int> &vals)
{
    vector<int> sol(target + 1, 0);
    sol.at(0) = 1;

    findTD(target, sol, vals);

    return sol.at(target);
}

int
main()
{
    cout << sol(4, { 1, 2, 3 }) << "\n";
}
