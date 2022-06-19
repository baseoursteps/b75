#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// You are given an array of non-overlapping intervals intervals where
// intervals[i] = [starti, endi] represent the start and the end of the ith
// interval and intervals is sorted in ascending order by starti. You are also
// given an interval newInterval = [start, end] that represents the start and
// end of another interval.
//
// Insert newInterval into intervals such that intervals is still sorted in
// ascending order by starti and intervals still does not have any overlapping
// intervals (merge overlapping intervals if necessary).
//
// Return intervals after the insertion.

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
vector<vector<int>>
insert(vector<vector<int>> ints, const vector<int> &nint)
{
    size_t start;

    for (start = 0; start < ints.size(); ++start)
        if (ints.at(start).at(0) > nint.at(0))
            break;

    // insert
    ints.insert(ints.begin() + start, nint);

    // merge
    for (start = 0; start < ints.size() - 1;) {
        if (ints.at(start).at(0) >= ints.at(start + 1).at(0) ||
            ints.at(start).at(1) >= ints.at(start + 1).at(0)) {
            ints.at(start).at(0) =
                min(ints.at(start).at(0), ints.at(start + 1).at(0));
            ints.at(start).at(1) =
                max(ints.at(start).at(1), ints.at(start + 1).at(1));

            ints.erase(ints.begin() + start + 1);
        } else {
            start++;
        }
    }

    return ints;
}

void
sol(const vector<vector<int>> &intervals, const vector<int> &newInterval)
{
    for (auto &&ints : intervals)
        cout << "[" << ints.at(0) << "," << ints.at(1) << "], ";

    cout << " => adding [" << newInterval.at(0) << ", " << newInterval.at(1)
         << "]";

    cout << "\n Now is: \n";

    for (auto &&ints : insert(intervals, newInterval))
        cout << "[" << ints.at(0) << "," << ints.at(1) << "], ";

    cout << "\n\n";
}

int
main()
{
    vector<vector<int>> ints  = { { 1, 2 },
                                 { 3, 5 },
                                 { 6, 7 },
                                 { 8, 10 },
                                 { 12, 16 } },
                        ints2 = { { 1, 3 }, { 6, 9 } },
                        ints3 { { 1, 2 }, { 6, 7 } },
                        ints4 { { 11, 15 }, { 17, 23 } };

    vector<int> nint = { 4, 8 }, nint2 { 2, 5 }, nint3 { 3, 5 },
                nint4 { 9, 10 };

    sol(ints, nint);
    sol(ints2, nint2);
    sol(ints2, nint);
    sol(ints3, nint3);
    sol(ints3, nint4);
    sol(ints4, nint);
}
