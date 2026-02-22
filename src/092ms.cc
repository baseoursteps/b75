#include <algorithm>
#include <stack>

using namespace std;

class MinStack
{
public:
    using elem = pair<int, int>;
    stack<elem> s;

    MinStack() {}

    void
    push(int val)
    {
        int min = val;
        if (s.size()) {
            min = std::min(val, s.top().second);
        }

        s.push({ val, min });
    }

    void
    pop()
    {
        s.pop();
    }

    int
    top()
    {
        return s.top().first;
    }

    int
    getMin()
    {
        return s.top().second;
    }
};

int
main()
{
}
