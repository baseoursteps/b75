#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

bool
is_palin(const string &s, size_t start, size_t len)
{
    if (start + len > s.size())
        return false;

    for (size_t i = start, j = 1; i < (len + start) / 2; i++, j++)
        if (s.at(i) != s.at(start + len - j))
            return false;

    return true;
}

size_t
count_palindromes(const string &s)
{
    size_t count { 0 };

    for (size_t len = s.size(); len > 0; len--)
        for (size_t start = 0; start <= s.size() - len; start++)
            count += (is_palin(s, start, len) ? 1 : 0);

    return count;
}

int
main()
{
    const string a { "abc" }, b { "aaa" };

    cout << count_palindromes(a) << count_palindromes(b);

    cout << "\n";
}
