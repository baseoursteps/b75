#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// There is an integer array nums sorted in ascending order (with distinct
// values).
//
// Prior to being passed to your function, nums is possibly rotated at an
// unknown pivot index k (1 <= k < nums.length) such that the resulting array is
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
// (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
// and become [4,5,6,7,0,1,2].
//
// Given the array nums after the possible rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.
//
// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Input: nums = [1], target = 0
// Output: -1

int
search(const vector<int> nums, size_t i, size_t j, int target)
{
    if (i == nums.size() || j == nums.size())
        return -1;

    int front = nums.at(i);
    int mid   = nums.at((i + j) / 2);
    int back  = nums.at(j);

    if (target == mid)
        return (i + j) / 2;

    // front < mid < back => normal binary search    1 2 3 4 5 6
    // front > mid > back => reversed binary search  6 5 4 3 2 1
    // front > mid < back => reversed binary search  4 5 6 1 2 3
    // front < mid > back => normal binary search    3 4 5 6 1 2

    if (front < mid && mid < back) {
        if (target < mid) {
            return search(nums, i, (i + j) / 2, target);
        } else {
            return search(nums, (i + j) / 2, j, target);
        }
    } else if (front > mid && mid > back) {
        if (target < mid) {
            return search(nums, (i + j) / 2, j, target);
        } else {
            return search(nums, i, (i + j) / 2, target);
        }
    } else if (front > mid && mid < back) {
        if (target < mid && target < back) { // mid back
            return search(nums, (i + j) / 2, j, target);
        } else { // front mid
            return search(nums, i, (i + j) / 2, target);
        }
    } else if (front < mid && mid > back) {
        if (target < mid && target > front) { // front mid
            return search(nums, i, (i + j) / 2, target);
        } else { // mid back
            return search(nums, (i + j) / 2, j, target);
        }
    } else
        return -1;
}

int
search(const vector<int> &nums, int target)
{
    return search(nums, 0, nums.size() - 1, target);
}

int
search2(const vector<int> &nums, int target)
{
    size_t l = 0;
    size_t r = nums.size() - 1;

    while (l <= r) {
        const auto mid = l + (r - l) / 2;

        if (target == nums.at(l))
            return l;
        else if (target == nums.at(mid))
            return mid;
        else if (target == nums.at(r))
            return r;

        if (nums.at(l) < nums.at(r)) {
            if (target < nums.at(mid))
                r = mid;
            else
                l = mid + 1;
        } else if (nums.at(l) < nums.at(mid)) {
            if (target > nums.at(l) && target < nums.at(mid))
                r = mid;
            else
                l = mid + 1;
        } else if (nums.at(mid) < nums.at(r)) {
            if (target > nums.at(mid) && target < nums.at(r))
                l = mid + 1;
            else
                r = mid;
        } else {
            return -1;
        }
    }

    return -1;
}

void
sol(const vector<int> &vals, int target)
{
    cout << search2(vals, target) << "\n";
}

int
main()
{
    vector<int> v1 { 4, 5, 6, 7, 0, 1 }, v2 { 1 };
    int         t1 { 0 }, t2 { 3 };

    for (auto &&v : v1) {
        cout << v << " is at index: " << search2(v1, v) << "\n";
    }

    sol(v1, t1); // 4
    sol(v1, t2); // -1
    sol(v2, t1); // -1
}
