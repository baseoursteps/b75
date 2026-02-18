#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums, return an array answer such that answer[i] is
// equal to the product of all the elements of nums except nums[i].
//
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
// integer.
//
// You must write an algorithm that runs in O(n) time and without using the
// division operation.

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

int
divide(int num, int divisor)
{
    int minus { 1 };

    if (num * divisor < 0)
        minus = -1;

    num     = abs(num);
    divisor = abs(divisor);

    if (divisor == 1)
        return num;

    if (!divisor)
        return num;

    int rez = 0;
    while (num != 0) {
        num -= divisor;
        rez++;
    }

    return rez * minus;
}

vector<int>
productExceptSelfGarbage(const vector<int> &nums)
{
    int zeros = 0;
    int product { 1 };
    for (auto &&val : nums) {
        if (val) {
            product *= val;
        } else
            zeros++;
    }

    vector<int> rez;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (!nums.at(i)) {
            if (zeros > 1)
                rez.push_back(0);
            else
                rez.push_back(product);
        } else {
            if (zeros)
                rez.push_back(0);
            else
                rez.push_back(divide(product, nums.at(i)));
        }
    }

    return rez;
}

// basically every position represents all the other numbers to the left and
// right of it multiplied. so we have to accumulate both from left to right and
// right to left and update i and n-1 accordingly.
vector<int>
productExceptSelf(const vector<int> &nums)
{
    const size_t sz = nums.size();
    vector<int>  sol(sz, 1);

    int l2r = 1, r2l = 1;

    for (size_t i = 0; i < sz; ++i) {
        sol.at(i) *= l2r;
        l2r *= nums.at(i);

        sol.at(sz - i - 1) *= r2l;
        r2l *= nums.at(sz - i - 1);
    }

    return sol;
}

void
sol(const vector<int> &v)
{
    for (auto &&v : productExceptSelf(v))
        cout << v << " ";

    cout << "\n";
}

int
main()
{
    vector<int> v1 { 1, 2, 3, 4 }, v2 { -1, 1, 0, -3, 3 };
    sol(v1);
    sol(v2);
}
