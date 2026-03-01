#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

// Design a time-based key-value data structure that can store multiple values
// for the same key at different time stamps and retrieve the key's value at a
// certain timestamp.
//
// Implement the TimeMap class:
//
//  TimeMap() Initializes the object of the data structure.

//  void set(String key, String value, int timestamp) Stores the key key with
//  the value value at the given time timestamp.

//   String get(String key, int  timestamp) Returns a value such that set was
//   called previously, with timestamp_prev <= timestamp. If there are
//   multiple such values, it returns the value associated with the largest
//   timestamp_prev. If there are no values, it returns "".
//

class TimeMap
{
public:
    unordered_map<string, map<int, string>> mp;

    TimeMap() {}

    void
    set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string
    get(string key, int timestamp)
    {
        auto time_map = mp.find(key);

        if (time_map == mp.end()) {
            return {};
        } else {
            auto &tm = time_map->second;
            if (tm.count(timestamp)) {
                return tm[timestamp];
            } else {
                for (auto it = tm.rbegin(); it != tm.rend(); ++it) {
                    if (it->first < timestamp) {
                        return it->second;
                    }
                }
                return {};
            }
        }
    }
};

int
main()
{
    TimeMap tm;
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << "\n";
    cout << tm.get("foo", 3) << "\n";
    tm.set("foo", "bar2", 4);
    cout << tm.get("foo", 4) << "\n";
    cout << tm.get("foo", 5) << "\n";
}
