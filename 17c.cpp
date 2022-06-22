#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
//
// Return the fewest number of coins that you need to make up that amount. If
// that amount of money cannot be made up by any combination of the coins,
// return -1.
//
// You may assume that you have an infinite number of each kind of coin.

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

int
cc(vector<int> &coins, unordered_map<int, int> &sol, int amount)
{
    if (amount < 0)
        return -1;
    else if (sol.count(amount))
        return sol.at(amount);
    else {
        auto min { -1 };
        for (auto &&c : coins) {
            auto nm = cc(coins, sol, amount - c);
            if (nm >= 0) {
                if (min == -1)
                    min = nm + sol.at(c);
                else
                    min = std::min(nm + sol.at(c), min);
            }
        }
        sol.insert({ amount, min });
    }

    return sol.at(amount);
}

int
coinChange(vector<int> &coins, int amount)
{
    unordered_map<int, int> sol;
    sol.insert({ 0, 0 });

    for (auto &&c : coins)
        sol.insert({ c, 1 });

    return cc(coins, sol, amount);
}

int
main()
{
    vector<int> c1 { 1, 2, 5 }, c2 { 2 }, c3 { 1 };
    int         a1 { 11 }, a2 { 3 }, a3 { 0 };

    cout << coinChange(c1, a1) << " " << coinChange(c1, a2) << " "
         << coinChange(c2, a2) << " " << coinChange(c3, a3);

    cout << "\n";
}
