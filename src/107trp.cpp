#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it can trap after raining.
//
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array
// [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
// are being trapped.

int
trapShitty(vector<int> &height)
{
    size_t idx {};
    int    count {};

    while (idx < height.size() && !height.at(idx))
        idx++;

    if (idx == height.size())
        return count;

    // find next block
    while (idx + 1 < height.size()) {
        size_t n_idx;

        while (1) {
            n_idx = idx + 1;
            while (n_idx < height.size() && height.at(idx) > height.at(n_idx)) {
                n_idx++;
            }

            if (n_idx == height.size()) {
                height.at(idx)--;
            } else {
                break;
            }

            if (!height.at(idx)) {
                break;
            }
        }

        if (n_idx <= idx + 1 || !height.at(idx)) {
            height.at(idx) = 0;
            idx++;
        } else {
            count += (n_idx - idx - 1);
            height.at(idx)--;
        }

        // for (auto &&v : height)
        //     cout << v << " ";
        // cout << "\n";
    }

    return count;
}

// https://yewtu.be/watch?v=ZI2z5pq0TqA
// fml
int
trap(vector<int> &height)
{
    size_t l = 0, r = height.size() - 1;
    int    l_max { height.at(l) }, r_max { height.at(r) };

    int count {};

    while (l < r) {
        if (l_max < r_max) {
            l++;
            l_max = max(l_max, height.at(l));
            count += (l_max - height.at(l));
        } else {
            r--;
            r_max = max(r_max, height.at(r));
            count += (r_max - height.at(r));
        }
    }
    return count;
}

int
main()
{
    vector<int> vals { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }, vals2 { 0, 2, 0 },
        vals3 { 4, 2, 3 };

    cout << trap(vals3);

    cout << "\n";
}
