#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums, find a contiguous non-empty subarray within the
// array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// at every step we must compute the smallest and the biggest from the current
// and the current multiplied with the former max and min, and update the
// possible result
int
maxProduct(const vector<int> &nums)
{
    int mn { nums.at(0) }, mx { nums.at(0) }, res { nums.at(0) };
    int t1 { 0 }, t2 { 0 }, t3 { 0 };

    for (size_t i = 1; i < nums.size(); ++i) {
        t1 = nums.at(i);
        t2 = t1 * mn;
        t3 = t1 * mx;

        mx  = max(t1, max(t2, t3));
        mn  = min(t1, min(t2, t3));
        res = max(res, mx);
    }

    return res;
}

void
sol(const vector<int> &nums)
{
    cout << maxProduct(nums) << "\n";
}

int
main()
{
    vector<int> v1 { 2, 3, -2, 4 }, v2 { -2, 0, -1 }, v3 { 2, -3, -2, -4, 1 };

    sol(v1);
    sol(v2);
    sol(v3);
}
