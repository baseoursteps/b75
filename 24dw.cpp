#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

// A message containing letters from A-Z can be encoded into numbers using the
// following mapping:
//
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//
// To decode an encoded message, all the digits must be grouped then mapped back
// into letters using the reverse of the mapping above (there may be multiple
// ways). For example, "11106" can be mapped into:
//
//     "AAJF" with the grouping (1 1 10 6)
//     "KJF" with the grouping (11 10 6)
//
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
// into 'F' since "6" is different from "06".
//
// Given a string s containing only digits, return the number of ways to decode
// it.
//
// The test cases are generated so that the answer fits in a 32-bit integer.
//
// Input: s = "12"
// Output: 2
// Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
//
// Input: s = "226"
// Output: 3
// Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
// 2 6).
//
// Input: s = "06"
// Output: 0
// Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is
// different from "06").
bool
toChar(string_view a, size_t len)
{
    if (len == 1) {
        auto fc = a.at(0);
        if (fc > '0' && fc <= '9')
            return true;

    } else if (len == 2) {
        auto fc = a.at(0);
        if (fc > '0' && fc < '9') {
            auto sc  = a.at(1);
            int  num = (fc - '0') * 10 + sc - '0';
            if (num < 27)
                return true;
        }
    }

    return false;
}

int
numDecodingCached(string_view s, unordered_map<string_view, int> &sol)
{
    if (s.empty())
        return 1;

    int sum {};
    for (size_t i = 0; i < std::min(size_t(2), s.size()); ++i) {
        auto        fhr = toChar(s, i + 1);
        string_view sh  = s.substr(i + 1);

        if (fhr) {
            int    shr {};
            auto &&hit = sol.find(sh);
            if (hit != sol.end())
                shr = hit->second;
            else
                shr = numDecodingCached(sh, sol);

            if (shr)
                sum += shr;
        }
    }

    sol.insert({ s, sum });

    return sum;
}

int
numDecodings(string s)
{
    unordered_map<string_view, int> sol;
    return numDecodingCached(s, sol);
}

int
main()
{
    cout << numDecodings("11106");
    cout << "\n";
}
