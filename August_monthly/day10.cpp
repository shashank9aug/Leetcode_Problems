/*
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
*/

#include <iostream>
#include <string>
using namespace std;

int minFlipsMonoIncr(string s)
{
    int count_1 = 0;
    int count_0 = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            count_0++;
        }
        else
        {
            count_1++;
        }
    }

    int ans = count_0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            count++;
        }
        else
        {
            count_0--;
        }

        int t = count + count_0;

        if (t < ans)
        {
            ans = t;
        }
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;

    cout << minFlipsMonoIncr(str) << endl;

    return 0;
}