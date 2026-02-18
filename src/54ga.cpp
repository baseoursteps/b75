#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

vector<vector<string>>
groupAnagrams(vector<string> &strs)
{
    if (strs.empty())
        return {};

    vector<vector<string>> sol;

    unordered_map<string, vector<string>> mp;

    auto key = strs.back();
    std::sort(key.begin(), key.end(), [](auto a, auto b) {
        return a < b;
    });

    mp.insert({ key, vector<string>({ move(strs.back()) }) });

    for (ssize_t i = strs.size() - 2; i >= 0; --i) {
        auto key = strs.at(i);
        std::sort(key.begin(), key.end(), [](auto a, auto b) {
            return a < b;
        });

        auto &&fd = mp.find(key);
        if (fd != mp.end())
            fd->second.push_back(move(strs.at(i)));
        else
            mp.insert({ key, { move(strs.at(i)) } });
    }

    for (auto &&[_, v] : mp)
        sol.push_back(move(v));

    return sol;
}

void
sol(vector<string> vals)
{
    for (auto &&group : groupAnagrams(vals)) {
        for (auto &&val : group)
            cout << val << " ";

        cout << "\n";
    }
}

int
main()
{
    sol({ "eat", "tea", "tan", "ate", "nat", "bat" });
}
