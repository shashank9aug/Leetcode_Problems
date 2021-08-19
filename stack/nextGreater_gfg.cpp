#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nextGreater(vector<int> arr)
{
    int n=arr.size();
    vector<int> v;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        //last elment will always have -1 as next greater element
        if (st.size() == 0)
        {
            v.push_back(-1);
        }
        else if (st.size() > 0 and st.top() > arr[i])
        {
            v.push_back(st.top());
        }
        else if (st.size() > 0 and st.top() <= arr[i])
        {
            while (st.size() > 0 and st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    vector<int> ans = nextGreater(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}