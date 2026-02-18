#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Implement a first in first out (FIFO) queue using only two stacks. The
// implemented queue should support all the functions of a normal queue (push,
// peek, pop, and empty).
//
// Implement the MyQueue class:
//
//     void push(int x) Pushes element x to the back of the queue.
//     int pop() Removes the element from the front of the queue and returns it.
//     int peek() Returns the element at the front of the queue.
//     boolean empty() Returns true if the queue is empty, false otherwise.
//
// Notes:
//
//     You must use only standard operations of a stack, which means only push
//     to top, peek/pop from top, size, and is empty operations are valid.
//     Depending on your language, the stack may not be supported natively. You
//     may simulate a stack using a list or deque (double-ended queue) as long
//     as you use only a stack's standard operations.

class MyQueue
{
    vector<int> stack;

public:
    MyQueue() {}

    void
    push(int x)
    {
        vector<int> temp;
        while (stack.size()) {
            auto v = stack.back();
            stack.pop_back();
            temp.push_back(v);
        }

        temp.push_back(x);

        while (temp.size()) {
            auto v = temp.back();
            temp.pop_back();
            stack.push_back(v);
        }
    }

    int
    pop()
    {
        auto v = stack.back();
        stack.pop_back();
        return v;
    }

    int
    peek()
    {
        return stack.back();
    }

    bool
    empty()
    {
        return stack.empty();
    }
};

int
main()
{
    MyQueue q;

    for (int i = 0; i <= 100; ++i)
        q.push(i);

    for (int i = 0; i <= 100; ++i) {
        auto peeked = q.peek();
        auto popped = q.pop();

        if (peeked != i || popped != i)
            cout << "not ok\n";
    }
}
