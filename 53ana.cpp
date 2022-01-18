#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Given two strings s and t, return true if t is an anagram of s, and false
// otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

bool
is_anagram(const string &s, const string &t)
{
    unordered_map<char, size_t> chars;

    for (auto c : s)
        chars[c]++;

    for (auto c : t) {
        auto f = chars.find(c);

        if (f == chars.end())
            return false;
        else if (!--f->second)
            chars.erase(f);
    }

    return chars.empty();
}

int
main()
{
    cout << is_anagram("anagram", "nagaram") << " " << is_anagram("rat", "car")
         << "\n";
}
