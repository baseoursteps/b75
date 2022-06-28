#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed. All houses at this place are
// arranged in a circle. That means the first house is the neighbor of the last
// one. Meanwhile, adjacent houses have a security system connected, and it will
// automatically contact the police if two adjacent houses were broken into on
// the same night.
//
// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the
// police.

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
// 2), because they are adjacent houses.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

int
robber(const vector<int> &nums, ssize_t start, ssize_t stop)
{
    vector<int> sol(nums.size() + 2, 0);

    for (ssize_t i = stop; i >= start; i--) {
        auto nm = nums.at(i) + sol.at(i + 2);
        auto om = sol.at(i + 1);

        sol.at(i) = nm > om ? nm : om;
    }

    return sol.at(start);
}

int
robber2(const vector<int> &nums, ssize_t start, ssize_t stop)
{
    int new_max {}, old_max {};
    for (ssize_t i = start; i <= stop; ++i) {
        auto tmp = std::max(nums.at(i) + old_max, new_max);
        old_max  = new_max;
        new_max  = tmp;
    }

    return new_max;
}

int
rob(const vector<int> &nums)
{
    if (nums.size() == 1)
        return nums.at(0);

    auto fp = robber2(nums, 0, nums.size() - 2);
    auto sp = robber2(nums, 1, nums.size() - 1);

    return fp > sp ? fp : sp;
}

int
sol(const vector<int> &vals)
{
    auto res = rob(vals);

    cout << res << "\n";
    return res;
}

int
main()
{
    sol({ 2, 3, 2 });
    sol({ 1, 2, 3, 1 });
    sol({ 1, 2, 3 });
}
