/*
P.s : we have to verify the email address as it is valid or not.

Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int numUniqueEmails(vector<string> emails)
{
    set<string> se;
    //for each email
    for (string email : emails)
    {
        string temp = email;
        int i = temp.find('@');
        string domain = temp.substr(i);
        string ans;
        //traverse for local name
        for (int j = 0; j < i; j++)
        {
            if (email[j] == '.')
            {
                continue;
            }
            if (email[j] == '+')
            {
                break;
            }
            ans.push_back(email[j]);
        }
        ans += domain;
        se.insert(ans);
    }

    return se.size();
}

int main()
{
    int n;
    cin >> n;

    vector<string> st;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        st.push_back(str);
    }
    cout << numUniqueEmails(st) << endl;

    return 0;
}