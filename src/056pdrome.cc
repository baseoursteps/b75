#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads the
// same forward and backward. Alphanumeric characters include letters and
// numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

using namespace std;

bool
isPalindrome(string s)
{
    std::for_each(s.begin(), s.end(), [](auto &c) {
        c = std::tolower(c);
    });

    s.erase(std::remove_if(s.begin(),
                           s.end(),
                           [](auto c) {
                               return !std::isalnum(c);
                           }),
            s.end());

    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s.at(i) != s.at(s.size() - i - 1)) {
            return false;
        }
    }

    return true;
}

int
main()
{
    cout << isPalindrome("A man, a plan, a canal: Panama") << " "
         << isPalindrome("race a car") << " " << isPalindrome(" ") << "\n";
}
