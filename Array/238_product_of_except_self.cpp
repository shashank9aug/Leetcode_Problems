#include <iostream>
#include <vector>
using namespace std;

vector<int> productArray(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            ans[i] = ans[i] * nums[j];
        }
    }
    return ans;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;

    int zero = 0;
    int product = 1;
    for (auto x : nums)
    {
        if (x == 0)
        {
            zero = zero + 1;
        }
        else
        {
            product = product * x;
        }
    }

    for (auto x : nums)
    {
        if (x == 0)
        {
            if (zero != 1)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(product);
            }
        }
        else
        {
            if (zero == 0)
            {
                ans.push_back(product / x);
            }
            else
            {
                ans.push_back(0);
            }
        }
    }

    return ans;
}


//Best approach : O(n) -> time and O(1) -> space 
vector<int> productExceptSelf_1(vector<int> &nums)
{
    //T.c: o(N)  and space : O(1) without using division opertor
    vector<int> op;

    //product variable
    int product = 1;
    //create left cumulative
    for (int i = 0; i < nums.size(); i++)
    {
        product = product * nums[i];
        op.push_back(product);
    }

    //make product=1;
    product = 1;
    // traverse from back to maintain right array
    for (int i = nums.size() - 1; i > 0; i--)
    {
        op[i] = op[i - 1] * product;
        product *= nums[i];
    }
    //for 0th element op will be product
    op[0] = product;

    return op;
}

int main()
{
    int n;
    cout << "Enter array length : ";
    cin >> n;
    vector<int> ip;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        ip.push_back(d);
    }

    vector<int> op = productArray(ip);

    for (int i = 0; i < op.size(); i++)
    {
        cout << op[i] << " ";
    }
    cout<<endl;
    vector<int> op1 = productExceptSelf(ip);

    for (int i = 0; i < op1.size(); i++)
    {
        cout << op1[i] << " ";
    }
    cout<<endl;
    vector<int> op2 = productExceptSelf(ip);

    for (int i = 0; i < op2.size(); i++)
    {
        cout << op2[i] << " ";
    }

    return 0;
}