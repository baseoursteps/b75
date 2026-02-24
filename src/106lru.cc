#include <cstddef>
#include <list>
#include <unordered_map>
#include <utility>

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
private:
    using Key   = int;
    using Value = int;
    const size_t                                         m_capacity;
    list<pair<Key, Value>>                               m_list;
    unordered_map<Key, list<pair<Key, Value>>::iterator> m_trick;

public:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int
    get(int key)
    {
        auto it = m_trick.find(key);
        if (it != m_trick.end()) {
            m_list.splice(m_list.begin(), m_list, it->second);
            return it->second->second;
        } else {
            return -1;
        }
    }

    void
    put(int key, int value)
    {
        auto it = m_trick.find(key);

        if (it != m_trick.end()) {
            it->second->second = value;
            m_list.splice(m_list.begin(), m_list, it->second);
        } else {
            m_list.push_front({ key, value });
            m_trick.insert({ key, m_list.begin() });
        }

        if (m_list.size() > m_capacity) {
            auto evict = m_list.back();
            m_list.pop_back();
            m_trick.erase(evict.first);
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
