#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// You are given a string s and an integer k. You can choose any character of
// the string and change it to any other uppercase English character. You can
// perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can
// get after performing the above operations.

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

size_t
longest(const string &s, size_t k)
{
    size_t       max { 1 };
    size_t       first { 0 };
    const size_t orig_k { k };

    while (first < s.size()) {
        size_t next = first + 1;

        for (; next < s.size(); ++next) {
            if (s.at(next) != s.at(first)) {
                if (!k)
                    break;
                else
                    --k;
            }
        }

        if (next - first > max)
            max = next - first;

        first = s.find_first_not_of(s.at(first), first);
        k     = orig_k;
    }

    return max;
}

int
main()
{
    cout << longest("ABAB", 1) << " " << longest("AABABBA", 2) << " "
         << longest("AABABA", 0) << "\n";
}
