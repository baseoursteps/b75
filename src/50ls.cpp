#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Given a string s, find the length of the longest substring without repeating
// characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.

size_t
longest(const string &s)
{
    if (s.size() < 2)
        return s.size();

    size_t max { 0 };
    size_t first { 0 };

    while (first < s.size()) {
        unordered_set<char> chars;
        chars.insert(s.at(first));

        size_t j = first + 1;

        for (; j < s.size() && chars.count(s.at(j)) == 0; ++j)
            chars.insert(s.at(j));

        if (j - first > max)
            max = j - first;

        first = j;
    }

    return max;
}

int
main()
{
    cout << longest("abcabcbb") << " " << longest("bbbbb") << " "
         << longest("pwwkew") << " " << longest("qwertyuiop") << " "
         << longest("a") << " " << longest("ab") << "\n";
}
