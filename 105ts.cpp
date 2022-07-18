#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

// Given a characters array tasks, representing the tasks a CPU needs to do,
// where each letter represents a different task. Tasks could be done in any
// order. Each task is done in one unit of time. For each unit of time, the CPU
// could complete either one task or just be idle.
//
// However, there is a non-negative integer n that represents the cooldown
// period between two same tasks (the same letter in the array), that is that
// there must be at least n units of time between any two same tasks.
//
// Return the least number of units of times that the CPU will take to finish
// all the given tasks.
//
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation:
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.

// First count the number of occurrences of each element.
//
// Let the max frequency seen be M for element E
//
// We can schedule the first M-1 occurrences of E, each E will be followed by at
// least N CPU cycles in between successive schedules of E
//
// Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1
// comes for the CPU cycle for E itself
//
// Now schedule the final round of tasks. We will need at least 1 CPU cycle of
// the last occurrence of E. If there are multiple tasks with frequency M, they
// will all need 1 more cycle.
//
// Run through the frequency dictionary and for every element which has
// frequency == M, add 1 cycle to result.
//
// If we have more number of tasks than the max slots we need as computed above
// we will return the length of the tasks array as we need at least those many
// CPU cycles.
int
leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, size_t> count;

    size_t most_freq {};
    for (auto &&t : tasks) {
        count[t]++;
        most_freq = max(count[t], most_freq);
    }

    // this is magic, ngl
    auto ans = (most_freq - 1) * (n + 1);

    for (auto &&[_, freq] : count)
        if (freq == most_freq)
            ans++;

    return max(ans, tasks.size());
}

void
sol(vector<char> tasks, int n)
{
    cout << leastInterval(tasks, n) << "\n";
    for (auto &&t : tasks)
        cout << char(t) << " ";
    cout << "\n";
}

int
main()
{
    // 8
    sol({ 'A', 'A', 'A', 'B', 'B', 'B' }, 2);

    // 6
    sol({ 'A', 'A', 'A', 'B', 'B', 'B' }, 0);

    // 16
    sol({ 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' }, 2);

    // 12
    sol({ 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E' }, 2);
}
