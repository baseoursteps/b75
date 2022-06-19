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
merge(vector<vector<int>> vals)
{
    for (size_t i = 0; i < vals.size() - 1;) {
        if (vals.at(i).at(0) >= vals.at(i + 1).at(0) ||
            vals.at(i).at(1) >= vals.at(i + 1).at(0)) {
            vals.at(i).at(0) = min(vals.at(i).at(0), vals.at(i + 1).at(0));
            vals.at(i).at(1) = max(vals.at(i).at(1), vals.at(i + 1).at(1));

            vals.erase(vals.begin() + i + 1);
        } else
            i++;
    }

    return vals;
}

void
sol(const vector<vector<int>> &vals)
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
