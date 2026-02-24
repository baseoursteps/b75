#include <iostream>
#include <string>
#include <sys/types.h>

using namespace std;

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

bool
isPalindrome(const std::string &s, int begin, int size)
{
    if (begin + size > s.size()) {
        return false;
    }

    for (int i = 0; i < size / 2; ++i) {
        if (s[begin + i] != s[begin + size - i - 1]) {
            return false;
        }
    }
    return true;
}

string
longestPalindrome(string s)
{
    for (int sz = int(s.size()); sz > 0; --sz) {
        for (int begin = 0; begin + sz <= s.size(); ++begin) {
            if (isPalindrome(s, begin, sz)) {
                return s.substr(begin, sz);
            }
        }
    }

    return "";
}

int
main()
{
    const string a = "babad", b = "cbbd";

    cout << longestPalindrome(a) << " " << longestPalindrome(b);
    cout << "\n";
}
