#include <algorithm>
#include <array>
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

vector<array<int, 3>>
twoSum(vector<int> &nums, int target, size_t skip)
{
    unordered_map<int, size_t> val;
    vector<array<int, 3>>      sol;

    for (size_t i = skip + 1; i < nums.size(); i++)
        val.insert({ nums.at(i), i });

    for (size_t i = skip + 2; i < nums.size(); ++i) {
        auto &&f = val.find(-nums.at(i) - target);

        if (f != val.end() && f->second != i) {
            array<int, 3> vals({ target, nums.at(i), f->first });
            sort(vals.begin(), vals.end()); // could i get away without this
            sol.push_back(vals);
        }
    }

    return sol;
}

vector<vector<int>>
threeSum(vector<int> nums)
{
    vector<vector<int>> sol;
    set<array<int, 3>>  sols;

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++)
        for (auto &&s : twoSum(nums, nums.at(i), i))
            sols.insert(s); // could i get away without this

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
