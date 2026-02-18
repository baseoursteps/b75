#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Given an integer n, return an array ans of length n + 1 such that for each i
// (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
//
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

int
count(int n)
{
    int c { 0 };

    while (n) {
        c++;
        n &= (n - 1);
    }

    return c;
}

vector<int>
countBits(int n)
{
    vector<int> sol;

    for (int i = 0; i <= n; ++i)
        sol.push_back(count(i));

    return sol;
}

// so the idea is that any number can be imagined as X/2 = Y where bitCount(X) -
// bitCount(Y) <= 1, then there are two cases, when X is ODD or when it's EVEN
vector<int>
countBitsBest(int n)
{
    // n+1 as we are going to count from [0 to n]
    vector<int> t(n + 1, 0);

    // we can compute current set bit count using previous count
    // as x/2 in O(1) time

    // i%2 will be 0 for even number ans 1 for odd number
    for (int i = 1; i <= n; ++i)
        t.at(i) = t.at(i / 2) + i % 2;

    return t;
}

int
main()
{
    for (auto &&b : countBitsBest(5))
        cout << b << " ";

    cout << "\n";
}
