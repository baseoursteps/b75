#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.
//
// You must solve this problem without using the library's sort function.
//
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

void
sortColors(vector<int> &nums)
{
    size_t start = 0, end = nums.size() - 1;
    int    first_color = 0;

    while (true) {
        while (start < end && nums.at(start) == first_color)
            start++;

        while (end > start && nums.at(end) != first_color)
            end--;

        if (start < end)
            swap(nums.at(start), nums.at(end));
        else if (!first_color) {
            end         = nums.size() - 1;
            first_color = 1;
        } else
            break;
    }
}

int
main()
{
    vector<int> colors { 2, 0, 2, 1, 1, 0 };
    sortColors(colors);

    for (auto &&c : colors)
        cout << c << " ";

    cout << "\n";
}
