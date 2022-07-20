#include <cstddef>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// Design a data structure that follows the constraints of a Least Recently Used
// (LRU) cache.
//
// Implement the LRUCache class:
//
//     LRUCache(int capacity) Initialize the LRU cache with positive size
//     capacity.
//
//     int get(int key) Return the value of the key if the key exists, otherwise
//     return -1.
//
//     void put(int key, int value) Update the value of the key if the key
//     exists. Otherwise, add the key-value pair to the cache. If the number of
//     keys exceeds the capacity from this operation, evict the least recently
//     used key.
//
// The functions get and put must each run in O(1) average time complexity.

class LRUCache
{
    const size_t                                       cap;
    unordered_map<int, list<pair<int, int>>::iterator> keys;
    list<pair<int, int>>                               vals;

public:
    LRUCache(int capacity) : cap(capacity) {};

    void
    put(int key, int value)
    {
        auto &&f = keys.find(key);

        // update
        if (f != keys.end()) {
            f->second->second = value;
            // move to front
            vals.splice(vals.begin(), vals, f->second);
        } else {
            // evict
            if (keys.size() == cap) {
                keys.erase(vals.back().first);
                vals.pop_back();
            }
            vals.emplace_front(key, value);
            keys.insert({ key, vals.begin() });
        }
    }

    int
    get(int key)
    {
        auto &&f = keys.find(key);
        if (f == keys.end()) {
            return -1;
        } else {
            // move to front of list
            vals.splice(vals.begin(), vals, f->second);
            return vals.front().second;
        }
    }
};

int
main()
{
    LRUCache lRUCache(2);

    // lRUCache.put(1, 1); // cache is {1=1}
    // lRUCache.put(2, 2); // cache is {1=1, 2=2}
    //// cout << lRUCache;   //
    // lRUCache.get(1);    // return 1
    // lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lRUCache.get(2);    // returns -1 (not found)
    // cout << lRUCache << "\n";
    // lRUCache.put(4, 4);       // LRU key was 1, evicts key 1,
    // cout << lRUCache << "\n"; // cache is {4=4, 3=3}
    // lRUCache.get(1);          // return -1 (not found)
    // lRUCache.get(3);          // return 3
    // lRUCache.get(4);          // return 4

    //["LRUCache","put","put","get","put","put","get"]
    //[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
    lRUCache.put(2, 1);
    lRUCache.put(2, 2);
    lRUCache.get(2);
    lRUCache.put(1, 1);
    lRUCache.put(4, 1);
    lRUCache.get(2);
}
