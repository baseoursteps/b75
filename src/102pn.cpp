#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order.
//
// A mapping of digits to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.
//
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
// Input: digits = "2"
// Output: ["a","b","c"]

// combinations of letters corresponding to digits taken digits.size() i suppose
void
combs(vector<string> &ltrs,
      vector<string> &sol,
      string         &comb,
      size_t          pos,
      size_t          cs)
{
    if (comb.size() == cs)
        sol.push_back(comb);

    for (size_t i = pos; i < ltrs.size(); ++i) {
        for (size_t j = 0; j < ltrs.at(i).size(); ++j) {
            comb.push_back(ltrs.at(i).at(j));
            combs(ltrs, sol, comb, i + 1, cs);
            comb.pop_back();
        }
    }
}

vector<string>
letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    const unordered_map<char, string> mp { { '2', "abc" }, { '3', "def" },
                                           { '4', "ghi" }, { '5', "jkl" },
                                           { '6', "mno" }, { '7', "pqrs" },
                                           { '8', "tuv" }, { '9', "wxyz" } };

    vector<string> ltrs;

    for (auto &&s : digits)
        ltrs.push_back(mp.at(s));

    vector<string> sol;
    string         tmp;

    combs(ltrs, sol, tmp, 0, digits.size());

    return sol;
}

void
sol(string digits)
{
    for (auto &&v : letterCombinations(digits))
        cout << v << " ";

    cout << "\n";
}

int
main()
{
    sol("23");
}
