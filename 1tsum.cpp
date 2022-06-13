#include <iostream>
#include <unordered_map>
#include <vector>

// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
using namespace std;

// go through `nums` and keep a mapping of `target - nums.at(i)` => `i`.
// go again through `nums` and search for `nums.at(i)`. if found and `i` !=
// current index save solution
vector<size_t>
sol(vector<int> &nums, int target)
{
    unordered_map<int, size_t> mp;

    for (size_t i = 0; i < nums.size(); ++i) {
        mp.insert({ target - nums.at(i), i });
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        auto idx = mp.find(nums.at(i));
        if (idx != mp.end() && idx->second != i) {
            return { i, idx->second };
        }
    }

    return {};
}

int
main()
{
    vector<int> nums { 2, 7, 11, 15 };
    int         target { 9 };

    for (auto &&v : sol(nums, target)) {
        cout << v << " ";
    }

    cout << "\n";
}
