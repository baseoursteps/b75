#include <iostream>
#include <unordered_set>
#include <vector>

// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

// Why is this at graph category? wtf?
using namespace std;

size_t
count(const vector<int> &nums)
{
    unordered_set<int> vals(nums.begin(), nums.end());
    size_t             max { 1 };
    for (auto &&i = vals.begin(); i != vals.end(); ++i) {
        if (vals.find((*i) - 1) != vals.end()) {
            max++;
            continue;
        }

        size_t sz { 1 };
        while (i != vals.end() && vals.find((*i) + 1) != vals.end()) {
            ++i;
            ++sz;
        }

        if (sz > max)
            max = sz;

        if (i == vals.end())
            break;
    }
    return max;
}

int
main()
{
    vector<int> nums { 100, 4, 200, 1, 3, 2 };
    vector<int> nums1 { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };

    cout << count(nums) << " " << count(nums1) << "\n";
}
