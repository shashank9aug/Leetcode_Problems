/*
abbaca
ca
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s)
{
    string ans = "";
    stack<char> st;

    //traverse the string :
    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];

        //if stack will be empty :
        if (st.empty())
        {
            st.push(curr);
        }
        //if top element matched :
        else if (st.top() == curr)
        {
            st.pop();
        }
        else
        {
            st.push(curr);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << removeDuplicates(s) << endl;

    return 0;
}