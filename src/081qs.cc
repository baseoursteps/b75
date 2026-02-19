#include <iostream>
#include <stack>

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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue
{
private:
    stack<int> s1, s2;

    void
    qify()
    {
        while (s1.size()) {
            auto top = s1.top();
            s1.pop();
            s2.push(top);
        }
    }

    void
    dqify()
    {
        while (s2.size()) {
            auto top = s2.top();
            s2.pop();
            s1.push(top);
        }
    }

public:
    MyQueue() {}

    void
    push(int x)
    {
        dqify();
        s1.push(x);
    }

    int
    pop()
    {
        qify();
        auto el = s2.top();
        s2.pop();
        return el;
    }

    int
    peek()
    {
        qify();
        auto el = s2.top();
        return el;
    }

    bool
    empty()
    {
        return s1.empty() && s2.empty();
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
