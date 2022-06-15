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
    int front = nums.front();
    int mid   = nums.at(nums.size() / 2);
    int back  = nums.back();

    // front < mid < back => get front
    // front > mid < back => search in (front, mid]
    // front < mid > back => search in (mid, back]
    // else front

    if (front < mid && mid < back)
        return front;
    else if (front > mid && mid < back) {
        vector<int> v(nums.begin(), nums.begin() + (nums.size() / 2));
        return findMin(v);
    } else if (front < mid && mid > back) {
        vector<int> v(nums.begin() + (nums.size() / 2) + 1, nums.end());
        return findMin(v);
    } else {
        return front;
    }
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
