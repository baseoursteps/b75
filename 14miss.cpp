#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Given an array nums containing n distinct numbers in the range [0, n], return
// the only number in the range that is missing from the array.

// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation: n = 9 since there are 9 numbers, so all numbers are in the range
// [0,9]. 8 is the missing number in the range since it does not appear in nums.

int
missingNumber(vector<int> &nums)
{
    const unsigned total_sum = (nums.size() * (nums.size() + 1)) / 2;
    const unsigned sum       = accumulate(nums.begin(), nums.end(), 0);
    return total_sum - sum;
}

// notice that the XOR operator is the only one that doesn't lose any data.
// therefore if we xor all the given numbers and all the possible numbers up to
// N we shall obtain the missing one
int
missingNumberBinary(vector<int> &nums)
{
    int ans { 0 };

    for (auto &&v : nums)
        ans ^= v;

    for (size_t i = 1; i <= nums.size(); i++)
        ans ^= i;

    return ans;
}

int
main()
{
    vector<int> v1 { 9, 6, 4, 2, 3, 5, 7, 0, 1 }, v2 { 3, 0, 1 };

    cout << missingNumberBinary(v1) << " " << missingNumberBinary(v2);

    cout << "\n";
}
