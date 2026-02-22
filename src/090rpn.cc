#include <stack>
#include <string>
#include <vector>
#include <iostream>

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

stack<int> nos;

int
evalRPN(const vector<string> &tokens)
{
    for (auto &&token : tokens) {
        if ((token.size() == 1 && std::isdigit(token.front())) ||
            token.size() > 1) {
            auto i = stoi(token);
            nos.push(i);
        } else {
            auto j = nos.top();
            nos.pop();
            auto i = nos.top();
            nos.pop();

            switch (token.front()) {
                case '+':
                    i += j;
                    break;
                case '-':
                    i -= j;
                    break;
                case '*':
                    i *= j;
                    break;
                case '/':
                    i /= j;
                    break;
                default:
                    break;
            }

            nos.push(i);
        }
    }

    return nos.top();
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
