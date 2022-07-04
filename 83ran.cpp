#include <algorithm>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Given two strings ransomNote and magazine, return true if ransomNote can be
// constructed by using the letters from magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote.

bool
canConstruct(string ransomNote, string magazine)
{
    if (magazine.size() < ransomNote.size())
        return false;

    if (ransomNote.empty())
        return true;

    unordered_map<char, int> chars;
    for (auto &&v : magazine)
        chars[v]++;

    bool ok { true };
    for (size_t i = 0; i < ransomNote.size() && ok; ++i) {
        auto &&f = chars.find(ransomNote.at(i));
        if (f == chars.end() || --f->second < 0)
            ok = false;
    }

    return ok;
}

int
main()
{
    cout << canConstruct("ab", "ab") << "\n";
}
