#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums of unique elements, return all possible subsets (the
power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
void
bt(vector<vector<int>> &sol,
   vector<int>         &tmp,
   const vector<int>   &nums,
   size_t               pos)
{
    sol.push_back(tmp);
    for (size_t i = pos; i < nums.size(); ++i) {
        tmp.push_back(nums.at(i));
        bt(sol, tmp, nums, i + 1);
        tmp.pop_back();
    }
};

vector<vector<int>>
subsets(const vector<int> &nums)
{
    vector<vector<int>> sol;
    vector<int>         tmp;
    bt(sol, tmp, nums, 0);
    return sol;
}

void
sol(vector<int> nums)
{
    for (auto &&s : subsets(nums)) {
        for (auto &&v : s)
            cout << v << " ";
        cout << "\n";
    }
}

int
main()
{
    sol({ 1, 2, 3 });
}
