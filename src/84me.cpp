#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an array nums of size n, return the majority element.
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. You
// may assume that the majority element always exists in the array.
//

int
majorityElement(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    return nums.at(nums.size() / 2);
}

// Could you solve the problem in linear time and in O(1) space?
// Boyer-Moore Majority Vote Algorithm
// http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
int
majorityElementPro(vector<int> &nums)
{
    int  count     = 1;
    auto candidate = nums.front();

    for (size_t i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            count     = 1;
            candidate = nums.at(i);
        } else if (candidate == nums.at(i))
            count++;
        else
            count--;
    }

    return candidate;
}

int
main()
{
    vector<int> vals { 2, 2, 1, 1, 1, 2, 2 };
    cout << majorityElement(vals) << "\n";
}
