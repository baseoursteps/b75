#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

vector<vector<int>>
permute(vector<int> &nums)
{
    vector<vector<int>> sol;
    sort(nums.begin(), nums.end());
    do {
        sol.push_back(nums);

    } while (next_permutation(nums.begin(), nums.end()));

    return sol;
}

void
heap(vector<vector<int>> &sol, vector<int> &nums, size_t sz)
{
    if (sz == 1) {
        sol.push_back(nums);
        return;
    }

    for (size_t i = 0; i < sz; ++i) {
        heap(sol, nums, sz - 1);
        if (sz % 2)
            swap(nums.at(i), nums.at(sz - 1));
        else
            swap(nums.at(0), nums.at(sz - 1));
    }
}

// heap's algo
vector<vector<int>>
permute2(vector<int> &nums)
{
    vector<vector<int>> sol;
    heap(sol, nums, nums.size());
    return sol;
}

void
sol(vector<int> nums)
{
    for (auto &&e : permute2(nums)) {
        for (auto &&v : e)
            cout << v << " ";
        cout << "\n";
    }
}

int
main()
{
    sol({ 1, 2, 3 });
    sol({ 0, 1 });
}
