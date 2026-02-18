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
isAnagram(string s, string t)
{
    unordered_map<char, int> letters;
    for (auto c : s) {
        letters[c]++;
    }

    for (auto c : t) {
        letters[c]--;
    }

    for (auto &&[_, v] : letters) {
        if (v != 0) {
            return false;
        }
    }

    return true;
}

int
main()
{
    cout << isAnagram("anagram", "nagaram") << " " << isAnagram("rat", "car")
         << "\n";
}
