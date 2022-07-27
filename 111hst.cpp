#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sys/types.h>
#include <utility>
#include <vector>

using namespace std;

// Given an array of integers heights representing the histogram's bar height
// where the width of each bar is 1, return the area of the largest rectangle in
// the histogram.
//
// Input: heights = [2,1,5,6,2,3]
// Output: 10
//
// Input: heights = [2,4]
// Output: 4

int
largestRectangleArea1(vector<int> heights)
{
    auto max = *std::max_element(heights.begin(), heights.end());

    int largest = 0;

    for (int i = 1; i <= max; ++i) {
        size_t begin = 0;
        int    nmax  = 0;
        while (begin < heights.size()) {
            if (heights.at(begin) < i) {
                largest = std::max(nmax, largest);
                nmax    = 0;
            } else {
                nmax += i;
            }
            begin++;
        }
        largest = std::max(nmax, largest);
    }
    return largest;
}

int
largestRectangleAreaB(vector<int> heights)
{
    int max {};
    for (ssize_t i = 0; i < ssize_t(heights.size()); ++i) {
        ssize_t j = i - 1, k = i + 1;

        int nmax { heights.at(i) };
        while (j >= 0 && heights.at(j) >= heights.at(i)) {
            nmax += heights.at(i);
            --j;
        }
        while (k < ssize_t(heights.size()) && heights.at(k) >= heights.at(i)) {
            nmax += heights.at(i);
            k++;
        }

        max = std::max(nmax, max);
    }
    return max;
}

int
largestRectangleAreaC(vector<int> heights)
{
    int max {};
    for (ssize_t i = 0; i < ssize_t(heights.size()); ++i) {
        if (heights.at(i) <= 0) {
            continue;
        }

        int        nmax { heights.at(i) };
        const auto orig = heights.at(i);

        for (ssize_t j = i - 1; j >= 0 && abs(heights.at(j)) >= orig; --j) {
            nmax += orig;
            if (heights.at(j) == orig) {
                heights.at(j) = -heights.at(j);
            }
        }

        for (ssize_t k = i + 1;
             k < ssize_t(heights.size()) && abs(heights.at(k)) >= orig;
             ++k) {
            nmax += orig;
            if (heights.at(k) == orig) {
                heights.at(k) = -heights.at(k);
            }
        }

        max = std::max(nmax, max);
    }
    return max;
}

int
largestRectangleArea(vector<int> heights)
{
    vector<pair<size_t, int>> st;
    int                       max {};

    st.emplace_back(0, heights.front());

    for (size_t i = 1; i < heights.size(); ++i) {
        auto start = i;
        while (st.size() && st.back().second > heights.at(i)) {
            auto &&[idx, val] = st.back();
            st.pop_back();
            max   = std::max(int(val * (i - idx)), max);
            start = idx;
        }
        st.emplace_back(start, heights.at(i));
    }

    while (st.size()) {
        auto &&[idx, val] = st.back();
        st.pop_back();
        max = std::max(int(val * (heights.size() - idx)), max);
    }

    return max;
}

int
main()
{
    cout << largestRectangleArea({ 2, 1, 5, 6, 2, 3 }) << "\n"; // 10
    cout << largestRectangleArea({ 2, 4 }) << "\n";             // 4
    cout << largestRectangleArea(
                { 3, 5, 5, 2, 5, 5, 6, 6, 4, 4, 1, 1, 2, 5, 5, 6, 6, 4, 1, 3 })
         << "\n"; // 24
}
