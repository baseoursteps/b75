#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// We have n jobs, where every job is scheduled to be done from startTime[i] to
// endTime[i], obtaining a profit of profit[i].
//
// You're given the startTime, endTime and profit arrays, return the maximum
// profit you can take such that there are no two jobs in the subset with
// overlapping time range.
//
// If you choose a job that ends at time X you will be able to start another job
// that starts at time X.

// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job.
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
// [20,20,100,70,60] Output: 150 Explanation: The subset chosen is the first,
// fourth and fifth job. Profit obtained 150 = 20 + 70 + 60.

int
schedule(const vector<vector<size_t>> &adj,
         int                           val,
         const vector<vector<int>>    &profit,
         unordered_map<size_t, int>   &done,
         unordered_set<size_t>        &vis)
{
    if (vis.count(val)) {
        return 0;
    }

    if (done.count(val)) {
        return done.at(val);
    }

    vis.insert(val);

    int nm { profit.at(val).at(2) };
    for (auto &&n : adj.at(val)) {
        nm =
            std::max(profit.at(val).at(2) + schedule(adj, n, profit, done, vis),
                     nm);
    }

    vis.erase(val);
    done.insert({ val, nm });

    return nm;
}

int
jobSchedulingA(vector<int> &startTime,
               vector<int> &endTime,
               vector<int> &profit)
{
    int                    mx {};
    vector<vector<size_t>> adj { startTime.size() + 1 };
    vector<vector<int>>    zpd { startTime.size() };

    for (size_t i = 0; i < startTime.size(); ++i) {
        zpd.at(i).push_back(startTime.at(i));
        zpd.at(i).push_back(endTime.at(i));
        zpd.at(i).push_back(profit.at(i));
    }

    std::sort(zpd.begin(), zpd.end(), [](auto &a, auto &b) {
        return a.at(0) < b.at(0);
    });

    for (size_t i = 0; i < zpd.size(); ++i) {
        for (size_t j = 0; j < zpd.size(); ++j) {
            if (i == j) {
                continue;
            }

            if (zpd.at(j).at(0) >= zpd.at(i).at(1)) {
                adj.at(i).push_back(j);
            }
        }
    }

    unordered_set<size_t>      vis;
    unordered_map<size_t, int> done;

    for (size_t i = 0; i < zpd.size(); ++i) {
        if (done.count(i)) {
            continue;
        }
        mx = std::max(schedule(adj, i, zpd, done, vis), mx);
    }

    return mx;
}

int
jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<tuple<int, int, int>> zpd { startTime.size() };

    for (size_t i = 0; i < startTime.size(); ++i) {
        zpd.emplace_back(endTime.at(i), startTime.at(i), profit.at(i));
    }

    std::sort(zpd.begin(), zpd.end());

    vector<pair<int, int>> dp { { 0, 0 } };

    for (auto &&[e, s, p] : zpd) {
        auto &&it =
            prev(upper_bound(dp.cbegin(), dp.cend(), make_pair(s + 1, 0)));

        if (it->second + p > dp.back().second) {
            dp.emplace_back(e, it->second + p);
        }
    }

    return dp.back().second;
}

int
main()
{
    vector<int> s1 { 1, 2, 3, 4, 6 }, e1 { 3, 5, 10, 6, 9 },
        p1 { 20, 20, 100, 70, 60 };
    cout << jobScheduling(s1, e1, p1) << "\n";
}
