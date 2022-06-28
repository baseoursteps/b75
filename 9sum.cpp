#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
vector<vector<int>>
tsum(vector<int> nums)
{
    vector<vector<int>> sol;

    if (nums.size() < 3)
        return sol;

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 2; ++i) {
        if (i && nums.at(i - 1) == nums.at(i))
            continue;

        size_t left  = i + 1;
        size_t right = nums.size() - 1;

        while (left < right) {
            auto sum = nums.at(i) + nums.at(left) + nums.at(right);
            if (sum == 0) {
                sol.push_back({ nums.at(i), nums.at(left), nums.at(right) });

                left++;
                while (left < right && nums.at(left) == nums.at(left - 1))
                    left++;

            } else if (sum > 0)
                --right;
            else
                ++left;
        }
    }

    return sol;
}

void
sol(const vector<int> &v)
{
    for (auto &&arr : tsum(v)) {
        for (auto &&v : arr)
            cout << v << " ";
        cout << "\n";
    }
    cout << "\n";
}
int
main()
{
    vector<int> vals { -1, 0, 1, 2, -1, -4 }, vals2 { 0, 0, 0 };

    sol(vals);
}
