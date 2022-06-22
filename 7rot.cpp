#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Suppose an array of length n sorted in ascending order is rotated between 1
// and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//
//     [4,5,6,7,0,1,2] if it was rotated 4 times.
//     [0,1,2,4,5,6,7] if it was rotated 7 times.
//
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
// in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//
// Given the sorted rotated array nums of unique elements, return the minimum
// element of this array.
//
// You must write an algorithm that runs in O(log n) time.

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
// times.

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

int
findMin(const vector<int> &nums)
{
    size_t left  = 0;
    size_t right = nums.size() - 1;

    while (left != right) {
        // if ordered
        if (nums.at(left) <= nums.at(right))
            return nums.at(left);

        const auto mid = left + (right - left) / 2;

        // bigger half until mid
        if (nums.at(left) <= nums.at(mid))
            left = mid + 1;
        else // bigger half from mid to right
            right = mid;
    }

    return nums.at(left);
}

void
sol(const vector<int> &nums)
{
    cout << findMin(nums) << "\n";
}

int
main()
{
    vector<int> v1 { 3, 4, 5, 1, 2 }, v2 { 11, 13, 15, 17 },
        v3 { 4, 5, 6, 7, 0, 1, 2 };

    sol(v1);
    sol(v2);
    sol(v3);
}
