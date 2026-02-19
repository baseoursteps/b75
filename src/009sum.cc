#include <algorithm>
#include <cstddef>
#include <iostream>
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
threeSum(vector<int> nums)
{
    vector<vector<int>> sol;

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        size_t lo = i + 1, hi = nums.size() - 1;

        while (lo < hi) {
            auto sum = nums[lo] + nums[hi] + nums[i];
            if (sum == 0) {
                sol.push_back({ nums[i], nums[lo], nums[hi] });
                lo++;
                hi--;

                while (lo < hi && nums[lo] == nums[lo - 1])
                    lo++;

                while (lo < hi && nums[hi] == nums[hi + 1])
                    hi--;
            } else if (sum > 0) {
                hi--;
            } else {
                lo++;
            }
        }
    }
    return sol;
}

void
sol(const vector<int> &v)
{
    for (auto &&arr : threeSum(v)) {
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
