#include <iostream>
#include <string>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.

using namespace std;

bool
is_valid(const string &pars)
{
    ssize_t round { 0 }, square { 0 }, curly { 0 };

    for (auto c : pars) {
        switch (c) {
            case '(':
                round++;
                break;
            case ')':
                if (!round--)
                    return false;
                break;
            case '[':
                square++;
                break;
            case ']':
                if (!square--)
                    return false;
                break;
            case '{':
                ++curly;
                break;
            case '}':
                if (!curly--)
                    return false;
                break;

            default:
                return false;
        }
    }

    return !(round || square || curly);
}

int
main()
{
    cout << is_valid("[()()]") << "\n";
}
