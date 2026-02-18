#include <algorithm>
#include <cctype>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cwctype>
#include <deque>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Given a string s representing a valid expression, implement a basic
// calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates
// strings as mathematical expressions, such as eval().

// Input: s = " 2-1 + 2 "
// Output: 3

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

// Constraints:

//     1 <= s.length <= 3 * 105

//     s consists of digits, '+', '-', '(', ')', and ' '.

//     s represents a valid expression.

//     '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
//     invalid).

//     '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
//     valid).

//     There will be no two consecutive operators in the input.

//     Every number and running calculation will fit in a signed 32-bit integer.

// what if i RPN it?

bool
isOp(char c)
{
    return c == '+' || c == '|';
}

bool
isPar(char c)
{
    return c == '(' || c == ')';
}

int
calculate(string s)
{
    int         sign { 1 };
    long        sum {};
    vector<int> stack;

    for (size_t i = 0; i < s.size(); ++i) {
        auto &v = s.at(i);

        if (isdigit(v)) {
            long num {};
            while (i < s.size() && isdigit(s.at(i))) {
                num = num * 10 + s.at(i) - '0';
                i++;
            }
            sum += num * sign;
            i--;

        } else if (v == '+') {
            sign = 1;
        } else if (v == '-') {
            sign = -1;
        } else if (v == '(') {
            stack.push_back(sum);
            stack.push_back(sign);
            sum  = 0;
            sign = 1;
        } else if (v == ')') {
            sign = stack.back();
            stack.pop_back();
            sum *= sign;
            sum += stack.back();
            stack.pop_back();
        }
    }

    return sum;
}

int
main()
{
    cout << calculate("(1+(4+5+2) - 3) + (6+8)") << "\n";
}
