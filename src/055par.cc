#include <iostream>
#include <stack>
#include <string>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.

using namespace std;

bool
isValid(string s)
{
    stack<char> st;
    for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }

            auto top = st.top();
            st.pop();

            if (c == ')' && top == '(') {
            } else if (c == ']' && top == '[') {
            } else if (c == '}' && top == '{') {
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int
main()
{
    cout << isValid("[]()[{()()}]") << isValid("[(])") << "\n";
}
