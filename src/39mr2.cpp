#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Problem: Given an array of meeting time intervals consisting of start and end
// times [[s1,e1],[s2,e2],…] (si < ei), find the minimum number of conference
// rooms required.
//
// For example, Given [[0, 30],[5, 10],[15, 20]], return 2.

// this one seems to be more or less the same as number of minimal deletions 37
int
minRooms(vector<vector<int>> vals)
{
    sort(vals.begin(), vals.end(), [](auto &&a, auto &&b) {
        return a.at(0) <= b.at(0);
    });

    int dels { 0 };
    for (size_t i = 0; i < vals.size() - 1;) {
        if (vals.at(i).at(1) > vals.at(i + 1).at(0)) {
            dels++;
            if (vals.at(i).at(1) - vals.at(i).at(0) >
                vals.at(i + 1).at(1) - vals.at(i + 1).at(0))
                vals.erase(vals.begin() + i);
            else
                vals.erase(vals.begin() + i + 1);

        } else
            ++i;
    }

    return dels + 1;
}

int
main()
{
    cout << minRooms({ { 0, 30 }, { 15, 20 }, { 5, 10 } });

    cout << "\n";
}
