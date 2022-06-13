#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool
containsDuplicate(vector<int> &nums)
{
    unordered_set<int> val { nums.begin(), nums.end() };
    return val.size() != nums.size();
}

int
main()
{
    vector<int> v1 { 1, 2, 3, 1 }, v2 { 1, 2, 3, 4 },
        v3 { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

    cout << containsDuplicate(v1) << " " << containsDuplicate(v2) << " "
         << containsDuplicate(v3) << "\n";
}
