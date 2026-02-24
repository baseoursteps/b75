#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], merge all
// overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

vector<vector<int>>
merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](auto &&a, auto &&b) {
        return a[0] < b[0];
    });

    for (size_t i = 1; i < intervals.size();) {
        auto &a = intervals[i - 1];
        auto &b = intervals[i];

        if (a[1] < b[0]) {
            ++i;
        } else {
            b[0] = std::min(a[0], b[0]);
            b[1] = std::max(a[1], b[1]);
            intervals.erase(intervals.begin() + i - 1);
        }
    }

    return intervals;
}

void
sol(vector<vector<int>> &vals)
{
    for (auto &&v : vals)
        cout << v.at(0) << " " << v.at(1) << " | ";

    cout << " => ";

    for (auto &&v : merge(vals))
        cout << v.at(0) << " " << v.at(1) << " | ";

    cout << "\n\n";
}

int
main()
{
    vector<vector<int>> ints = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } },
                        ints2 { { 1, 4 }, { 4, 5 } };

    sol(ints);
    sol(ints2);
}
