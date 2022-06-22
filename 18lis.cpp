#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums, return the length of the longest strictly
// increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting
// some or no elements without changing the order of the remaining elements. For
// example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4.

int call = 0;

int
len(vector<int> &nums, vector<int> &sol, size_t idx)
{
    call++;
    if (idx >= nums.size())
        return 0;
    else if (sol.at(idx) != -1)
        return sol.at(idx);
    else
        for (size_t i = idx + 1; i < nums.size(); ++i)
            sol.at(idx) =
                max(sol.at(idx),
                    len(nums, sol, i) + (nums.at(idx) < nums.at(i) ? 1 : 0));

    return sol.at(idx);
}

int
lengthOfLIS(vector<int> &nums)
{
    vector<int> sol(nums.size() + 1, -1);
    sol.at(nums.size() - 1) = 1;
    call                    = 0;
    auto s                  = len(nums, sol, 0);

    cout << "size(" << nums.size() << "), call(" << call << "), sol(" << s
         << ")\n";

    return s;
}

int
main()
{
    vector<int> v1 { 10, 9, 2, 5, 3, 7, 101, 18 }, v2 { 0, 1, 0, 3, 2, 3 },
        v3 { 7, 7, 7, 7, 7, 7, 7 };

    lengthOfLIS(v1);
    lengthOfLIS(v2);
    lengthOfLIS(v3);
    
    cout << "\n";
}
