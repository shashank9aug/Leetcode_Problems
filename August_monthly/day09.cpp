#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string addStrings(string num1, string num2)
{
    string ans = "";
    int carry = 0, val = 0, l1 = num1.size() - 1, l2 = num2.size() - 1, a = 0, b = 0;

    while (l1 >= 0 or l2 >= 0)
    {

        if (l1 >= 0)
        {
            a = num1[l1] - '0';
            l1--;
        }
        else
        {
            a = 0;
            l1--;
        }

        if (l2 >= 0)
        {
            b = num2[l2] - '0';
            l2--;
        }
        else
        {
            b = 0;
            l2--;
        }

        val = (a + b + carry) % 10;

        ans += ('0' + val);

        carry = (a + b + carry) / 10;
    }
    if (carry > 0)
    {
        ans += carry + '0';
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string str1,str2;

    cin>>str1>>str2;

    cout<<addStrings(str1,str2)<<endl;

    return 0;
}