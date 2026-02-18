#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an array of intervals intervals where intervals[i] = [starti, endi],
// return the minimum number of intervals you need to remove to make the rest of
// the intervals non-overlapping.

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are
// non-overlapping.

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals
// non-overlapping.

int
eraseOverlapIntervals(vector<vector<int>> &ints)
{
    // sort the intervals
    std::sort(ints.begin(), ints.end(), [](auto &&a, auto &&b) {
        return a.at(0) <= b.at(0) && a.at(1) <= b.at(1);
    });

    int dels { 0 };
    for (size_t i = 0; i < ints.size() - 1;) {
        // find any interval whose right end is bigger than the next's left
        if (ints.at(i).at(1) > ints.at(i + 1).at(0)) {
            dels++;

            // delete the widest interval
            if (ints.at(i).at(1) - ints.at(i).at(0) >
                ints.at(i + 1).at(1) - ints.at(i + 1).at(0))
                ints.erase(ints.begin() + i);
            else
                ints.erase(ints.begin() + i + 1);

        } else {
            ++i;
        }
    }

    return dels;
}

void
sol(vector<vector<int>> ints)
{
    cout << eraseOverlapIntervals(ints);
    cout << "\n";

    for (auto &&i : ints)
        cout << i.at(0) << " " << i.at(1) << " | ";

    cout << "\n\n";
}

int
main()
{
    vector<vector<int>> ints { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } },
        ints2 { { 1, 2 }, { 1, 2 }, { 1, 2 } }, ints3 { { 1, 2 }, { 2, 3 } };

    sol(ints);
    sol(ints2);
    sol(ints3);
}
