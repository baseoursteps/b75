#include "matrix.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Given a string s and a dictionary of strings wordDict, return true if s can
// be segmented into a space-separated sequence of one or more dictionary words.
//
// Note that the same word in the dictionary may be reused multiple times in the
// segmentation.

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
//
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple
// pen apple". Note that you are allowed to reuse a dictionary word.

// brute-force
bool
wordBreakBF(const string s, const vector<string> &words)
{
    for (size_t i = 0; i < words.size(); ++i) {
        auto ns = s;

        for (size_t j = i; j < words.size() + i;) {
            while (true) {
                auto val = ns.find(words.at(j % words.size()));

                if (val != s.npos)
                    ns.erase(val, words.at(j % words.size()).size());
                else {
                    j++;
                    break;
                }
            }
        }

        if (ns.empty())
            return true;
    }

    return false;
}

// how exactly would i do this DP?
bool
wordBreak(string s, const vector<string> &words)
{
    const unordered_set<string> wds(words.begin(), words.end());

    matrix<int> sol { s.size(), vector<int>(s.size(), 0) };

    for (size_t len = 0; len < s.size(); ++len) {
        for (size_t start = 0; start + len < s.size(); ++start) {
            auto ns = s.substr(start, len + 1);
            // cout << "\n" << ns << "\n";

            if (wds.count(ns))
                sol.at(start).at(start + len) = 1;
            else // sub-split
                // cout << "splitting:\n";
                for (size_t sub_len = 0; sub_len < len; ++sub_len) {
                    // auto fs = s.substr(start, sub_len + 1);
                    // auto rs = s.substr(start + sub_len + 1, len - sub_len);
                    // cout << start << ":" << start + sub_len << " "
                    //      << start + sub_len + 1 << ":" << start + len <<
                    //      "\n";
                    // cout << fs << " " << rs << "\n";

                    if (sol.at(start).at(start + sub_len) &&
                        sol.at(start + sub_len + 1).at(start + len)) {
                        sol.at(start).at(start + len) = 1;
                        break;
                    }
                }
        }
    }

    // print_matrix(sol);

    return sol.at(0).at(s.size() - 1);
}

int
main()
{
    cout << wordBreak("catsandog", { "cats", "dog", "sand", "and", "cat" })
         << " " << wordBreak("applepenapple", { "apple", "pen" }) << " "
         << wordBreak("leetcode", { "leet", "code" });

    cout << "\n";
}
