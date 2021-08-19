
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue
{
public:
    stack<T> s1, s2;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(T x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    T pop()
    {
        int curr = s1.top();
        s1.pop();
        return curr;
    }

    /** Get the front element. */
    T peek()
    {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << endl;
    cout << q.peek() << endl;
    cout << q.pop() << endl;
}
