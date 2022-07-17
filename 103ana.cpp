#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

// Given two strings s and p, return an array of all the start indices of p's
// anagrams in s. You may return the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.
//
//
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

bool
isAnagram(string a, const string &b)
{
    if (b.size() > a.size())
        return false;

    sort(a.begin(), a.end());

    if (a == b)
        return true;
    else
        return false;
}

vector<int>
findAnagramsTLE(string s, string p)
{
    sort(p.begin(), p.end());
    vector<int> sol;
    for (size_t i = 0; i < s.size(); i++)
        if (i + p.size() <= s.size())
            if (isAnagram(s.substr(i, p.size()), p))
                sol.push_back(i);

    return sol;
}

// sliding window
vector<int>
findAnagrams(string s, string p)
{
    if (s.size() < p.size())
        return {};

    array<unsigned, 26> s_w {}, p_w {};

    for (size_t i = 0; i < p.size(); ++i) {
        s_w.at(s.at(i) - 'a')++;
        p_w.at(p.at(i) - 'a')++;
    }

    vector<int> sol;

    if (p_w == s_w)
        sol.push_back(0);

    for (size_t i = p.size(); i < s.size(); ++i) {
        s_w.at(s.at(i - p.size()) - 'a')--;
        s_w.at(s.at(i) - 'a')++;
        if (s_w == p_w)
            sol.push_back(i - p.size() + 1);
    }

    return sol;
}

void
sol(string a, string b)
{
    for (auto &&i : findAnagrams(a, b))
        cout << i << " ";

    cout << "\n";
}

int
main()
{
    sol("cbaebabacd", "abc");
}
