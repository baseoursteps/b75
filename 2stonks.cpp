#include <iostream>
#include <vector>

using namespace std;

// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction. If you
// cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
// 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed
// because you must buy before you sell.

// store first elem as min
// take the next element and if it's bigger than min check if their
// delta is bigger than profit and update profit.
// update min comparing min and current element.
int
maxProfit(const vector<int> &prices)
{
    if (prices.size() < 2)
        return 0;

    int profit = 0;
    int curMin = prices.front();

    for (auto it = ++prices.begin(); it != prices.end(); ++it) {
        profit = max(profit, *it - curMin);
        curMin = min(curMin, *it);
    }

    return profit;
}

int
main()
{
    // 3 0 5
    vector<int> p1 { 7, 5, 3, 6, 4, 1 }, p2 { 5, 4, 3, 2, 1 },
        p3 { 7, 1, 5, 3, 6, 4 };

    cout << maxProfit(p1) << " " << maxProfit(p2) << " " << maxProfit(p3)
         << "\n";
}
