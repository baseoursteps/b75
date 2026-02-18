#include <cstddef>
#include <cstdint>
#include <iostream>

using namespace std;

// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100
// represents the unsigned integer 43261596, so return 964176192964176192 which
// its binary representation is 00111001011110000010100101000000.

// Input: n = 11111111111111111111111111111101
// Output:   3221225471 (10111111111111111111111111111111)
// Explanation: The input binary string 11111111111111111111111111111101
// represents the unsigned integer 4294967293, so return 3221225471 which its
// binary representation is 10111111111111111111111111111111.

// reverse, not flip...pay attention!
// Follow up: If this function is called many times, how would you optimize it?
uint32_t
reverseBits(uint32_t n)
{
    uint32_t revd { 0 };
    for (int i = 31; i >= 0; i--, n >>= 1)
        revd |= (n & 1) << i;

    return revd;
}

int
main()
{
    // 964176192 3221225471
    cout << reverseBits(43261596) << " " << reverseBits(4294967293);
    cout << "\n";
}
