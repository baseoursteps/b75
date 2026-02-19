#include <sstream>
#include <string>
using namespace std;

string
addBinary(string a, string b)
{
    auto it_a = a.rbegin(), it_b = b.rbegin();

    std::stringstream ss;

    bool carry {};
    while (it_a != a.rend() && it_b != b.rend()) {
        auto sum = (*it_a == '1') + (*it_b == '1') + carry;

        if (sum == 0) {
            ss << 0;
            carry = 0;
        } else if (sum == 1) {
            ss << 1;
            carry = 0;
        } else if (sum == 2) {
            ss << 0;
            carry = 1;
        } else if (sum == 3) {
            ss << 1;
            carry = 1;
        }

        it_a++;
        it_b++;
    }

    while (it_a != a.rend()) {
        auto sum = (*it_a == '1') + carry;

        if (sum == 0) {
            ss << 0;
            carry = 0;
        } else if (sum == 1) {
            ss << 1;
            carry = 0;
        } else if (sum == 2) {
            ss << 0;
            carry = 1;
        }

        it_a++;
    }

    while (it_b != b.rend()) {
        auto sum = (*it_b == '1') + carry;

        if (sum == 0) {
            ss << 0;
            carry = 0;
        } else if (sum == 1) {
            ss << 1;
            carry = 0;
        } else if (sum == 2) {
            ss << 0;
            carry = 1;
        }

        it_b++;
    }

    if (carry) {
        ss << 1;
    }

    auto str = ss.str();

    return { str.rbegin(), str.rend() };
}

int
main()
{
}
