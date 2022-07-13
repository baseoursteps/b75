#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

// Given a list of accounts where each element accounts[i] is a list of strings,
// where the first element accounts[i][0] is a name, and the rest of the
// elements are emails representing emails of the account.
//
// Now, we would like to merge these accounts. Two accounts definitely belong to
// the same person if there is some common email to both accounts. Note that
// even if two accounts have the same name, they may belong to different people
// as people could have the same name. A person can have any number of accounts
// initially, but all of their accounts definitely have the same name.
//
// After merging the accounts, return the accounts in the following format: the
// first element of each account is the name, and the rest of the elements are
// emails in sorted order. The accounts themselves can be returned in any order.

// Input: accounts =
// [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output:
// [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email
// "johnsmith@mail.com". The third John and Mary are different people as none of
// their email addresses are used by other accounts. We could return these lists
// in any order, for example the answer [['Mary', 'mary@mail.com'], ['John',
// 'johnnybravo@mail.com'],
//['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
// would still be accepted.

class Solution
{
private:
    string_view
    find(string_view email)
    {
        return email == parents.at(email) ? email : find(parents.at(email));
    }

    unordered_map<string_view, string_view>      owner;
    unordered_map<string_view, string_view>      parents;
    unordered_map<string_view, set<string_view>> unions;

    vector<vector<string_view>>
    union_find(vector<vector<string>> &acts)
    {
        for (auto &&acc : acts)
            for (size_t i = 1; i < acc.size(); ++i) {
                owner.insert({ acc.at(i), acc.at(0) });
                // initially each mail is its own parent
                parents.insert({ acc.at(i), acc.at(i) });
            }

        for (auto &&acc : acts) {
            auto &&p = find(acc.at(1));
            for (size_t i = 2; i < acc.size(); ++i)
                // update parents of all emails for each entry to the parent of
                // the first email in the entry
                parents.at(find(acc.at(i))) = p;
        }

        for (auto &&acc : acts)
            for (size_t i = 1; i < acc.size(); ++i)
                unions[find(acc.at(i))].insert(acc.at(i));

        vector<vector<string_view>> sols;
        for (auto &&[prt, mails] : unions) {
            vector<string_view> sol;
            sol.push_back(owner.at(prt));
            move(mails.begin(), mails.end(), back_inserter(sol));
            sols.push_back(move(sol));
        }

        return sols;
    }

public:
    vector<vector<string>>
    accountsMerge(vector<vector<string>> &acts)
    {
        vector<vector<string>> sol;
        auto                   vals = union_find(acts);

        for (auto &&entry : vals) {
            vector<string> owned;
            for (auto &&sv : entry)
                owned.emplace_back(sv);
            sol.push_back(owned);
        }

        return sol;
    }
};

int
main()
{
    vector<vector<string>> vals1 {
        { "John", "johnsmith@mail.com", "john_newyork@mail.com" },
        { "John", "johnsmith@mail.com", "john00@mail.com" },
        { "Mary", "mary@mail.com" },
        { "John", "johnnybravo@mail.com" }
    },
        vals2 { { "David", "David0@m.co", "David1@m.co" },
                { "David", "David3@m.co", "David4@m.co" },
                { "David", "David4@m.co", "David5@m.co" },
                { "David", "David2@m.co", "David3@m.co" },
                { "David", "David1@m.co", "David2@m.co" } },
        vals3 { { "David", "David4@m.co", "David2@m.co", "David4@m.co" },
                { "John", "John7@m.co", "John5@m.co", "John3@m.co" },
                { "Fern", "Fern6@m.co", "Fern4@m.co", "Fern5@m.co" },
                { "Celine", "Celine0@m.co", "Celine7@m.co", "Celine7@m.co" },
                { "Gabe", "Gabe8@m.co", "Gabe8@m.co", "Gabe1@m.co" },
                { "Ethan", "Ethan1@m.co", "Ethan6@m.co", "Ethan6@m.co" },
                { "Celine", "Celine4@m.co", "Celine8@m.co", "Celine6@m.co" },
                { "Celine", "Celine0@m.co", "Celine0@m.co", "Celine4@m.co" } };

    Solution s;

    for (auto &&val : s.accountsMerge(vals2)) {
        for (auto &&s : val)
            cout << s << " ";

        cout << "\n";
    }
}
