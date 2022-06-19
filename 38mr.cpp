#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an array of meeting time intervals consisting of start and end
// times[[s1,e1],[s2,e2],…](si< ei), determine if a person could attend all
// meetings.

bool
canAttend(vector<vector<int>> vals)
{
    sort(vals.begin(), vals.end(), [](auto &&a, auto &&b) {
        return a.at(0) < b.at(0);
    });

    for (size_t i = 0; i < vals.size() - 1; ++i)
        if (vals.at(i).at(1) > vals.at(i + 1).at(0))
            return false;

    return true;
}

int
main()
{
    vector<vector<int>> vals { { 0, 30 }, { 5, 10 }, { 15, 20 } },
        vals1 { { 0, 2 }, { 5, 7 }, { 2, 4 } };

    cout << canAttend(vals) << " " << canAttend(vals1);

    cout << "\n";
}
