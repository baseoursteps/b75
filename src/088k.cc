#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// Given an array of points where points[i] = [xi, yi] represents a point on the
// X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//
// The distance between two points on the X-Y plane is the Euclidean distance
// (i.e., √(x1 - x2)2 + (y1 - y2)2).
//
// You may return the answer in any order. The answer is guaranteed to be unique
// (except for the order that it is in).

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just
// [[-2,2]].

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.

struct Comparator
{
    int
    edistance(const vector<int> &a)
    {
        return (a[0] * a[0]) + (a[1] * a[1]);
    }

    bool
    operator()(const vector<int> &a, const vector<int> &b)
    {
        return edistance(a) > edistance(b);
    }
};

vector<vector<int>>
kClosest(vector<vector<int>> &points, int k)
{
    Comparator c;

    make_heap(points.begin(), points.end(), c);

    vector<vector<int>> sol;

    for (int i = 0; i < k; ++i) {
        sol.push_back(points.front());
        pop_heap(points.begin(), points.end(), c);
        points.pop_back();
    }

    return sol;
}

void
sol(vector<vector<int>> vals, int k)
{
    for (auto &&arr : kClosest(vals, k)) {
        for (auto &&v : arr)
            cout << v << " ";

        cout << "\n";
    }
}

int
main()
{
    vector<vector<int>> vals { { -2, 2 }, { 1, 3 } };

    sol(vals, 1);
}
