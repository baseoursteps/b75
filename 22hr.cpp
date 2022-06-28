#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security systems
// connected and it will automatically contact the police if two adjacent houses
// were broken into on the same night.
//
// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the
// police.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
// (money = 1). Total amount you can rob = 2 + 9 + 1 = 12.

// we also need combination that jump more than one house

int
robber(const vector<int> &nums)
{
    vector<int> sol(nums.size() + 2, 0);

    for (ssize_t i = nums.size() - 1; i >= 0; i--) {
        auto nm = nums.at(i) + sol.at(i + 2);
        auto om = sol.at(i + 1);

        sol.at(i) = nm > om ? nm : om;
    }

    return sol.at(0);
}

int
robber2(const vector<int> &nums)
{
    int new_max {}, old_max {};
    for (size_t i = 0; i <= nums.size(); ++i) {
        auto tmp = std::max(nums.at(i) + old_max, new_max);
        old_max  = new_max;
        new_max  = tmp;
    }

    return new_max;
}

int
sol(const vector<int> &vals)
{
    auto sol = robber(vals);

    cout << sol << "\n";

    return sol;
}

int
main()
{
    sol({ 1, 2, 3, 1 });
    sol({ 2, 7, 9, 3, 1 });
    sol({ 4, 1, 2, 7, 5, 3, 1 });
}
