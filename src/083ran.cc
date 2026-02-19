#include <iostream>
#include <unordered_map>

using namespace std;

// Given two strings ransomNote and magazine, return true if ransomNote can be
// constructed by using the letters from magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote.

bool
canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, ssize_t> count;
    for (auto c : magazine) {
        count[c]++;
    }

    for (auto c : ransomNote) {
        count[c]--;
    }

    for (auto &&[_, c] : count) {
        if (c < 0) {
            return false;
        }
    }

    return true;
}

int
main()
{
    cout << canConstruct("ab", "ab") << "\n";
}
