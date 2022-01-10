#include <iostream>
#include <vector>

#include "heap.hpp"

using namespace std;

// The median is the middle value in an ordered integer list. If the size of the
// list is even, there is no middle value and the median is the mean of the two
// middle values.

//     For example, for arr = [2,3,4], the median is 3.

//     For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

// Implement the MedianFinder class:

//     MedianFinder() initializes the MedianFinder object.

//     void addNum(int num) adds the integer num from the data stream to the
//     data structure.

//     double findMedian() returns the median of all elements so far. Answers
//     within 10-5 of the actual answer will be accepted.

struct MedianFinder
{
    Heap<int, Type::Min> heap;
    vector<int>          sorted;

    void
    insert(int num)
    {
        heap.insert(num);
    }

    double
    find_median()
    {
        while (!heap.empty())
            sorted.push_back(heap.pop_front().value());

        if (sorted.size() % 2)
            return sorted.at(sorted.size() / 2);
        else
            return (sorted.at(sorted.size() / 2) +
                    sorted.at(sorted.size() / 2 - 1)) /
                   2.0;
    }
};

int
main()
{
    MedianFinder mf;
    for (int i = 1; i <= 10; ++i) {
        mf.insert(i);
        cout << mf.find_median() << "\n";
    }

    cout << "\n";
}
