#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Input: nums = [5,4,-1,7,8]
// Output: 23
int
maxSubArray(const vector<int> &nums)
{
    int nmx { nums.at(0) }, total { nums.at(0) }, mx { nums.at(0) };

    for (size_t i = 1; i < nums.size(); ++i) {
        total += nums.at(i);

        if (nmx < 0 || nmx + nums.at(i) < 0)
            nmx = nums.at(i);
        else
            nmx += nums.at(i);

        mx = max(nmx, mx);
    }

    return max(total, mx);
}

int
main()
{
    vector<int> v1 { -2, 1, -3, 4, -1, 2, 1, -5, 4 }, v2 { 5, 4, -1, 7, 8 },
        v3 { -1, -2, -3, -4, -5 }, v4 { 1, 0, 3, -5, 7, 9, -10, 4 };

    cout << "rez: " << maxSubArray(v1) << " " << maxSubArray(v2) << " "
         << maxSubArray(v3) << " " << maxSubArray(v4) << "\n";
}
