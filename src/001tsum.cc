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
vector<int>
twoSum(vector<int> &nums, int target)
{
    unordered_map<int, size_t> processed;
    for (size_t i = 0; i < nums.size(); ++i) {
        int  found = target - nums.at(i);
        auto it    = processed.find(found);
        if (it != processed.end()) {
            return { int(it->second), int(i) };
        }
        processed.insert({ nums.at(i), i });
    }
    return {};
}

int
main()
{
    vector<int> nums { 2, 7, 11, 15 };
    int         target { 9 };

    for (auto &&v : twoSum(nums, target)) {
        cout << v << " ";
    }

    cout << "\n";
}
