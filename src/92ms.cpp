#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
private:
    vector<array<int, 2>> vals;

public:
    MinStack() {}

    void
    push(int val)
    {
        array<int, 2> tpl;

        if (vals.empty())
            tpl = { val, val };
        else
            tpl = { val, min(vals.back().back(), val) };

        vals.push_back(tpl);
    }

    void
    pop()
    {
        vals.pop_back();
    }

    int
    top()
    {
        return vals.back().front();
    }

    int
    getMin()
    {
        return vals.back().back();
    }
};

int
main()
{
}
