#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

// Given two strings s and t of lengths m and n respectively, return the minimum
// window substring of s such that every character in t (including duplicates)
// is included in the window. If there is no such substring, return the empty
// string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
// from string t.

string
windows(const string &s, const string &t)
{
    size_t min = s.size() + 1;
    size_t start { 0 }, end { 0 };

    for (size_t first = 0; first < s.size(); ++first) {
        auto orig_t = t;
        first       = s.find_first_of(orig_t, first);
        if (first == s.npos)
            break;

        orig_t.erase(orig_t.find(s.at(first)), 1);

        size_t next = first + 1;

        while (!orig_t.empty()) {
            next = s.find_first_of(orig_t, next);
            if (next == s.npos)
                break;

            orig_t.erase(orig_t.find(s.at(next)), 1);
        }

        if (orig_t.empty() && next - first < min) {
            min   = next - first;
            start = first;
            end   = next;
        }
    }

    if (min != s.size() + 1)
        return s.substr(start, end - start + 1);
    else
        return {};
}

int
main()
{
    cout << windows("ADOBECODEBANC", "ABC") << " " << windows("a", "a") << " "
         << windows("a", "aa") << "\n";
}
