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
is_palindrome(string s)
{
    s.erase(remove_if(s.begin(),
                      s.end(),
                      [](char c) {
                          return !isalnum(c);
                      }),
            s.end());

    for (size_t i = 0; i < s.size() / 2; ++i)
        if (tolower(s.at(i)) != tolower(s.at(s.size() - i - 1)))
            return false;

    return true;
}

int
main()
{
    cout << is_palindrome("A man, a plan, a canal: Panama") << " "
         << is_palindrome("race a car") << " " << is_palindrome(" ") << "\n";
}
