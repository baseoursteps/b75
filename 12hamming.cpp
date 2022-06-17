#include <cstddef>
#include <iostream>

using namespace std;

// Write a function that takes an unsigned integer and returns the number of '1'
// bits it has (also known as the Hamming weight).

// optimised version. the number of iterations matches the number of set bits
int
hammingWeight(uint32_t n)
{
    int count { 0 };
    while (n) {
        count++;
        n = n & (n - 1);
        n >>= 1;
    }

    return count;
}

int
main()
{
    for (size_t i = 0; i <= 16; ++i)
        cout << i << " has " << hammingWeight(i) << "bits set\n";

    cout << "\n";
}
