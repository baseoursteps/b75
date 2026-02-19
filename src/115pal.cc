#include <string>
#include <unordered_set>

using namespace std;

int
longestPalindrome(string s)
{
    int                 res {};
    unordered_set<char> chars;

    for (auto c : s) {
        if (chars.count(c)) {
            res += 2;
            chars.erase(c);
        } else {
            chars.insert(c);
        }
    }

    if (chars.size())
        res++;

    return res;
}

int
main()
{
}
