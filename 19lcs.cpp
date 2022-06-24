#include "matrix.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given two strings text1 and text2, return the length of their longest common
// subsequence. If there is no common subsequence, return 0.
//
// A subsequence of a string is a new string generated from the original string
// with some characters (can be none) deleted without changing the relative
// order of the remaining characters.
//
//     For example, "ace" is a subsequence of "abcde".
//
// A common subsequence of two strings is a subsequence that is common to both
// strings.

int
lcs(string a, string b)
{
    // shorter one on the lines, longer one on the columns
    if (a.size() > b.size())
        swap(a, b);

    matrix<int> sol({ a.size() + 1, vector<int>(b.size() + 1, 0) });

    for (size_t i = 0; i < a.size(); ++i)
        for (size_t j = 0; j < b.size(); ++j)
            sol.at(i + 1).at(j + 1) =
                max(sol.at(i).at(j) + (a.at(i) == b.at(j) ? 1 : 0),
                    sol.at(i + 1).at(j));

    return sol.at(a.size()).at(b.size());
}

int
main()
{
    cout << lcs("ace", "abcde") << " " << lcs("abcde", "ace") << " "
         << lcs("abc", "abc") << " " << lcs("abc", "def") << " "
         << lcs("abbc", "bbbbbbbbbb");

    cout << "\n";
}
