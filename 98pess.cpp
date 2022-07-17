#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Given a non-empty array nums containing only positive integers, find if the
// array can be partitioned into two subsets such that the sum of elements in
// both subsets is equal.
//
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

bool
isSubsetSum(vector<int> &nums, int sum)
{
    vector<bool> dp(sum + 1);
    dp.front() = true;

    for (auto num : nums)
        for (auto i = sum; i >= num; --i)
            dp.at(i) = dp.at(i) || dp.at(i - num);

    return dp.at(sum);
}

bool
canPartition(vector<int> &nums)
{
    auto sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum & 1)
        return false;

    return isSubsetSum(nums, sum / 2);
}

int
main()
{
    vector<int> nums { 1, 5, 11, 5 }, nums2 { 1, 2, 3, 5 };

    cout << canPartition(nums) << canPartition(nums2);

    cout << "\n";
}
