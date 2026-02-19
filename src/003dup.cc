#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool
containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums.at(i) == nums.at(i - 1)) {
            return true;
        }
    }
    return false;
}
int
main()
{
    vector<int> v1 { 1, 2, 3, 1 }, v2 { 1, 2, 3, 4 },
        v3 { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

    cout << containsDuplicate(v1) << " " << containsDuplicate(v2) << " "
         << containsDuplicate(v3) << "\n";
}
