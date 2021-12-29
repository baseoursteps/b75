#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Problem: Given a sorted dictionary (array of words) of an alien language,
// find order of characters in the language.

// Example(s): Input: words[] = {“baa”, “abcd”, “abca”, “cab”, “cad”} Output:
// Order of characters is ‘b’, ‘d’, ‘a’, ‘c’

// i think we need a topological sort ...?
int
main()
{
    // // b d a c
    //  vector<string> words { "baa", "abcd", "abca", "cab", "cad" };
    // // w e r t f
    vector<string> words { "wrt", "wrf", "er", "ett", "rftt" };

    unordered_map<char, size_t>              degrees;
    unordered_map<char, unordered_set<char>> vals;

    for (auto &&w : words)
        for (auto c : w)
            degrees.insert({ c, 0 });

    for (size_t i = 0; i < words.size() - 1; ++i) {
        auto fw = words.at(i);
        auto sw = words.at(i + 1);

        auto len = min(fw.size(), sw.size());

        for (size_t j = 0; j < len; ++j) {
            auto cf = fw.at(j);
            auto cs = sw.at(j);

            if (cf != cs) {
                if (!vals.count(cf))
                    vals.insert({ cf, {} });

                auto &chars = vals.at(cf);
                if (!chars.count(cs)) {
                    chars.insert(cs);
                    degrees.at(cs) += 1;
                }
                break;
            }
        }
    }

    for (auto &&[k, v] : degrees)
        cout << (char)k << " " << v << "\n";

    deque<char> alphabet, temp;

    for (auto &&[k, v] : degrees)
        if (v == 0)
            temp.push_back(k);

    while (!temp.empty()) {
        auto v = temp.front();
        temp.pop_front();
        alphabet.push_back(v);

        if (vals.count(v))
            for (auto c : vals.at(v)) {
                degrees.at(c) -= 1;
                if (!degrees.at(c))
                    temp.push_back(c);
            }
    }

    for (auto a : alphabet)
        cout << (char)a << " ";

    cout << "\n";
}
