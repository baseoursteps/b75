#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, and /. Each operand may be an integer or another
// expression.
//
// Note that division between two integers should truncate toward zero.
//
// It is guaranteed that the given RPN expression is always valid. That means
// the expression would always evaluate to a result, and there will not be any
// division by zero operation.

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22

int
eval(int n1, int n2, char op)
{
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            throw std::runtime_error("should not be here");
    }
}

bool
is_op(string_view op)
{
    if (op.size() > 1) //-11 or 121
        return false;
    else {
        switch (op.at(0)) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }
}

int
evalRPN(const vector<string> &tokens)
{
    vector<int> tok;

    for (auto &&val : tokens) {
        if (!is_op(val))
            tok.push_back(atoi(val.c_str()));
        else {
            auto n2 = tok.back();
            tok.pop_back();
            auto n1 = tok.back();
            tok.pop_back();
            auto rez = eval(n1, n2, val.at(0));
            tok.push_back(rez);
        }
    }

    return tok.back();
}

int
main()
{
    cout << evalRPN({ "10",
                      "6",
                      "9",
                      "3",
                      "+",
                      "-11",
                      "*",
                      "/",
                      "*",
                      "17",
                      "+",
                      "5",
                      "+" })
         << "\n";

    cout << evalRPN({ "4", "13", "5", "/", "+" });

    cout << "\n";
}
