#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

set<vector<int>>
twoSum(vector<int> &nums, int target, size_t skip)
{
    unordered_map<int, size_t> val;

    set<vector<int>> sol;

    for (size_t i = 0; i < nums.size(); i++) {
        if (i == skip)
            continue;

        val.insert({ nums.at(i), i });
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        if (i == skip)
            continue;

        auto &&f = val.find(-(nums.at(i) + target));

        if (f != val.end() && f->second != i) {
            vector<int> vals({ target, nums.at(i), f->first });
            sort(vals.begin(), vals.end());
            sol.insert(vals);
        }
    }

    return sol;
}

vector<vector<int>>
threeSum(vector<int> nums)
{
    // -4 -1 -1 0 1 2
    // sort(nums.begin(), nums.end());

    vector<vector<int>> sol;
    set<vector<int>>    sols;

    for (size_t i = 0; i < nums.size(); i++)
        for (auto &&s : twoSum(nums, nums.at(i), i))
            sols.insert(s);

    for (auto &&s : sols)
        sol.push_back({ s.begin(), s.end() });

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
    vector<int> vals { -1, 0, 1, 2, -1, -4 };
    sol(vals);
}
