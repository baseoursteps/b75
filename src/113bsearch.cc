#include <cstddef>
#include <vector>

using namespace std;

int
search(vector<int> &nums, int target)
{
    size_t lo = 0;
    size_t hi = nums.size();
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (target > nums.at(mid)) {
            lo = mid + 1;
        } else if (target < nums.at(mid)) {
            hi = mid;
        } else {
            return mid;
        }
    }

    return -1;
}

int
main()
{
}
