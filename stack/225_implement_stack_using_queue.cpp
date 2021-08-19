#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<T> q1, q2;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(T x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        T ans = top();
        q1.pop();
        return ans;
    }

    /** Get the top element. */
    T top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    cout << st.pop() << endl;
}