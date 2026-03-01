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
    size_t              left {}, right {};
    size_t              max {};
    unordered_set<char> st;

    for (right = 0; right < s.size(); ++right) {
        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }
        st.insert(s[right]);
        max = std::max(max, st.size());
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
