#include <iostream>
#include <string>
#include <tuple>
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
    using min_map  = tuple<int, unordered_map<int, string>>;
    using time_map = unordered_map<string, min_map>;

    time_map vals;

public:
    TimeMap() {}

    void
    set(string key, string value, int timestamp)
    {
        if (!vals.count(key))
            vals.insert(
                { move(key), { timestamp, { { timestamp, move(value) } } } });
        else {
            auto &[min, times] = vals.at(key);
            if (timestamp < min)
                min = timestamp;

            times.insert({ timestamp, move(value) });
        }
    }

    string
    get(string key, int timestamp)
    {
        auto &&v = vals.find(key);
        if (v == vals.end())
            return {};
        else {
            auto &&[min, times] = v->second;
            if (times.count(timestamp))
                return times.at(timestamp);
            else
                while (timestamp >= min) {
                    timestamp--;
                    auto &&rez = times.find(timestamp);
                    if (rez != times.end())
                        return rez->second;
                }

            return {};
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
