#include <iostream>
#include <string>
#include <sys/types.h>

using namespace std;

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

bool
is_palin(const string &s, size_t start, size_t len)
{
    if (start + len > s.size())
        return false;

    for (size_t i = start, j = 1; i < (start + len) / 2; ++i, ++j)
        if (s.at(i) != s.at(start + len - j))
            return false;

    return true;
}

string
lps(const string &a)
{
    bool   ok { false };
    size_t i, sz;

    for (sz = a.size(); sz > 1 && !ok; sz--)
        for (i = 0; i <= a.size() - sz && !ok; i++)
            if (is_palin(a, i, sz))
                ok = true;

    if (ok)
        return a.substr(i - 1, sz + 1);
    else
        return "";
}

int
main()
{
    const string a = "babad", b = "cbbd";

    cout << lps(a) << " " << lps(b);
    cout << "\n";
}
