#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// You are a product manager and currently leading a team to develop a new
// product. Unfortunately, the latest version of your product fails the quality
// check. Since each version is developed based on the previous version, all the
// versions after a bad version are also bad.
//
// Suppose you have n versions [1, 2, ..., n] and you want to find out the first
// bad one, which causes all the following ones to be bad.
//
// You are given an API bool isBadVersion(version) which returns whether version
// is bad. Implement a function to find the first bad version. You should
// minimize the number of calls to the API.

// The API isBadVersion is defined for you.
bool
isBadVersion(int version)
{
    if (version >= 7)
        return true;

    return false;
}

int
firstBadVersion(int n)
{
    int l = 1;
    int r = n;

    while (l < r) {
        auto mid = l + (r - l) / 2;
        if (isBadVersion(mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int
main()
{
    cout << firstBadVersion(16) << "\n";
}
