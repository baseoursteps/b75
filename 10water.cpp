#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

// You are given an integer array height of length n. There are n vertical lines
// drawn such that the two endpoints of the ith line are (i, 0) and (i,
// height[i]).
//
// Find two lines that together with the x-axis form a container, such that the
// container contains the most water.
//
// Return the maximum amount of water a container can store.
//
// Notice that you may not slant the container.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array
// [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
// container can contain is 49.

// this seems to be a greedy problem
// we need max((xj-xi) * min(yj, yi))
//
// brute force
int
maxArea(const vector<int> &height)
{
    // maximum possible
    int max_val { 0 };

    for (size_t i = 0; i < height.size() - 1; ++i)
        for (size_t j = i + 1; j < height.size(); ++j) {
            int nmax = (j - i) * min(height.at(i), height.at(j));
            if (nmax > max_val)
                max_val = nmax;
        }

    return max_val;
}

// start from outmost indeces and compute area.
// next, whichever of the two lines is smaller increment(or decrement) its index
// compute new max and do this while left index is smaller than right
int
maxArea2(const vector<int> &h)
{
    int max_val { 0 }, nmax { max_val };

    size_t i = 0;
    size_t j = h.size() - 1;

    while (i < j) {
        nmax    = int(j - i) * min(h.at(j), h.at(i));
        max_val = max(nmax, max_val);

        if (h.at(i) < h.at(j))
            i++;
        else
            j--;
    }

    return max_val;
}

int
main()
{
    vector<int> v1 { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    cout << maxArea2(v1);

    cout << "\n";

    return 0;
}
