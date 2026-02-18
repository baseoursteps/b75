#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// You are given an integer array nums. You are initially positioned at the
// array's first index, and each element in the array represents your maximum
// jump length at that position.
//
// Return true if you can reach the last index, or false otherwise.

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
// jump length is 0, which makes it impossible to reach the last index.

bool
canJump(const vector<int> &nums)
{
    int prev { 1 };
    for (int i = nums.size() - 2; i >= 0; --i) {
        const auto jumps = nums.at(i);
        if (jumps < prev)
            prev++;
        else
            prev = 1;
    }

    return prev == 1;
}

int
main()
{
    cout << canJump({ 2, 3, 1, 1, 4 }) << " " << canJump({ 3, 2, 1, 0, 4 })
         << " " << canJump({ 3, 0, 8, 2, 0, 0, 1 }) << " "
         << "\n";
}
