#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <string_view>
#include <sys/types.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// A transformation sequence from word beginWord to word endWord using a
// dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
// such that:
//
//     Every adjacent pair of words differs by a single letter.
//     Every si for 1 <= i <= k is in wordList. Note that beginWord does not
//     need to be in wordList. sk == endWord
//
// Given two words, beginWord and endWord, and a dictionary wordList, return the
// number of words in the shortest transformation sequence from beginWord to
// endWord, or 0 if no such sequence exists.
//
//
// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
// -> "dog" -> cog", which is 5 words long.

bool
one_diff(string_view src, string_view dst)
{
    uint8_t cnt {};
    for (size_t i = 0; i < src.size() && cnt < 2; ++i) {
        cnt += (src.at(i) != dst.at(i));
    }

    return cnt < 2;
}

// graph bfs
int
ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
        return 0;
    }

    bool contains { false };
    if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
        wordList.push_back(beginWord);
    } else {
        contains = true;
    }

    unordered_map<string_view, vector<string_view>> adj;
    for (size_t i = 0; i < wordList.size(); ++i) {
        for (size_t j = 0; j < wordList.size(); ++j) {
            if (i == j) {
                continue;
            }
            if (one_diff(wordList.at(i), wordList.at(j))) {
                adj[wordList.at(i)].push_back(wordList.at(j));
            }
        }
    }

    int mn = contains ? 1 : 2;

    queue<string_view>         q;
    unordered_set<string_view> vis;

    q.push(beginWord);
    while (q.size()) {
        auto nq = move(q);
        while (nq.size()) {
            auto val = nq.front();
            nq.pop();
            vis.insert(val);

            for (auto &&n : adj.at(val)) {
                if (n == endWord) {
                    return mn;
                } else if (!vis.count(n)) {
                    q.push(n);
                }
            }
        }
        mn++;
    }

    return 0;
}

void
sol(string begin, string end, vector<string> vals)
{
    cout << ladderLength(begin, end, vals) << "\n";
}

int
main()
{
    sol("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
    sol("hot", "dog", { "hot", "dog", "dot" });
    sol("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
}
