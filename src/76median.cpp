#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

#include "heap.hpp"

using namespace std;

// The median is the middle value in an ordered integer list. If the size of the
// list is even, there is no middle value and the median is the mean of the two
// middle values.

//  For example, for arr = [2,3,4], the median is 3.

//  For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

//  Implement the MedianFinder class:

//  MedianFinder() initializes the MedianFinder object.

//  void addNum(int num) adds the integer num from the data stream to the
//  data structure.

//  double findMedian() returns the median of all elements so far. Answers
//  within 10-5 of the actual answer will be accepted.

// We need to keep two heaps --

// (U) -- a max-heap representing the lower half of the stream that always
// yields the biggest number amongst the smallest ones.

// (L) -- a min-heap representing the upper half of the stream that always
// yields the smallest of the larger numbers.

// if ever the size difference between (U) and (L) reaches two we need to
// rebalance by popping an element from the longer and pushing into the smaller

// the median is always the mean of the two fronts (if the halves are equal) or
// the front of the longer one

struct MedianFinder
{
    Heap<int, Type::Max> lower_h;
    Heap<int, Type::Min> upper_h;

    void
    insert(int num)
    {
        if (lower_h.empty())
            lower_h.insert(num);
        else if (upper_h.empty())
            upper_h.insert(num);
        else if (num <= lower_h.front().value())
            lower_h.insert(num);
        else
            upper_h.insert(num);

        if (lower_h.size() - upper_h.size() == 2)
            upper_h.insert(lower_h.pop_front().value());
        else if (upper_h.size() - lower_h.size() == 2)
            lower_h.insert(upper_h.pop_front().value());
    }

    optional<double>
    find_median() const
    {
        if (lower_h.empty() && upper_h.empty())
            return {};
        else if (lower_h.size() == upper_h.size())
            return (lower_h.front().value() + upper_h.front().value()) / 2.0;
        else if (upper_h.size() > lower_h.size())
            return upper_h.front();
        else
            return lower_h.front();
    }
};

template<typename T>
double
median(T vals)
{
    sort(vals.begin(), vals.end());
    if (vals.size() % 2)
        return vals.at(vals.size() / 2);
    else
        return (vals.at(vals.size() / 2) + vals.at(vals.size() / 2 - 1)) / 2.0;
}

int
main()
{
    MedianFinder mf;
    unsigned     seed = time(nullptr);
    vector<int>  vals;

    for (int i = 0; i < 15; ++i) {
        auto r = rand_r(&seed) % 1023;
        mf.insert(r);
        vals.push_back(r);
        std::printf("%6.2f should be %6.2f\n",
                    mf.find_median().value(),
                    median(vals));
    }

    cout << "\n";
}
