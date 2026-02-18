#include "heap.hpp"

#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Input: nums = [1], k = 1
// Output: [1]

// we need to sort by count somehow because we can have something like
// [1,2,3,3,3], k = 1 => 3
template<typename T>
struct elem
{
    T      m_val { 0 };
    size_t m_count { 0 };

    bool
    operator<(const elem<T> &other) const
    {
        return m_count < other.m_count;
    }
};

// TODO
// could we drop the map somehow??
template<typename T>
vector<T>
topK(const vector<T> &vals, size_t k)
{
    Heap<elem<T>, Type::Max>  h;
    unordered_map<T, elem<T>> elems;

    for (auto &&e : vals) {
        auto &v = elems[e];
        v.m_count++;
        v.m_val = e;
    }

    for (auto &&[_, v] : elems)
        h.insert(v);

    vector<int> sol;
    for (size_t i = 0; i < k; ++i)
        sol.push_back(h.pop_front().value().m_val);

    for (auto &&v : sol)
        cout << v << " ";

    cout << "\n";

    return sol;
}

int
main()
{
    topK<int>({ 1, 1, 1, 2, 2, 3 }, 2);
    topK<int>({ 1 }, 1);
    topK<int>({ 1, 2, 3, 3 }, 1);
}
