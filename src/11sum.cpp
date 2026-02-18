#include <cstddef>
#include <cstdint>
#include <iostream>

using namespace std;

// Given two integers a and b, return the sum of the two integers without using
// the operators + and-.

// what about negatives...?
int
getSum(int a, int b)
{
    int  rez { 0 };
    bool carry { false };

    for (size_t i = 0; i < (sizeof a) * 8; ++i) {
        const bool abit = a & 1, bbit = b & 1;
        a >>= 1;
        b >>= 1;

        rez |= ((abit ^ bbit ^ carry) << i);

        if ((abit && bbit) || (abit && carry) || (bbit && carry))
            carry = true;
        else
            carry = false;
    }

    return rez;
}

int
main()
{
    cout << getSum(-3, -2) << " " << getSum(1, 2) << " " << getSum(-1, 2) << " "
         << getSum(-1000, 1000);
    cout << "\n";
}
