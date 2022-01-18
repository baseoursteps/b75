#include <iostream>
#include <string>
#include <vector>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.

using namespace std;

bool
is_valid2(const string &pars)
{
    vector<char> pa;
    for (auto c : pars) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                pa.push_back(c);
                break;

            case ')':
                if (pa.empty() || pa.back() != '(')
                    return false;
                else
                    pa.pop_back();
                break;
            case ']':
                if (pa.empty() || pa.back() != '[')
                    return false;
                else
                    pa.pop_back();
                break;

            case '}':
                if (pa.empty() || pa.back() != '{')
                    return false;
                else
                    pa.pop_back();
                break;

            default:
                return false;
        }
    }

    return pa.empty();
}

int
main()
{
    cout << is_valid2("[]()[{()()}]") << is_valid2("[(])") << "\n";
}
