/*
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


$ ./a.exe
Enter n1 and n2 : 3 4
4 1 2
1 3 4 2

-1 3 -1 

*/

#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

//Brute force : Two nested loop.


/*
    Approach : store next greater element of num2 array in map and find the num1 array elements 
    in map and return stored next greater element in map 

    their is time duration gap while using map and unordered_map 
    # map
    - searching takes O(logN) in best case and worst case 
      because internally map stores element as balanced BST so searching takes o(logN)

    # unordered_map
    - In best case time take to search is o(1) 

    so unordered map suits best.      
*/
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    map<int, int> mp;
    stack<int> st;

    for (int i = (n - 1); i >= 0; i--)
    {
        while (!st.empty() and st.top() <= nums2[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (st.empty() == false)
            {
                mp[nums2[i]] = st.top();
            }
            else
            {
                mp[nums2[i]] = -1;
            }
        }
        st.push(nums2[i]);
    }
    vector<int> ans;

    for (auto it : nums1)
    {
        ans.push_back(mp[it]);
    }

    return ans;
}

int main()
{
    int n1, n2;
    cout << "Enter n1 and n2 : ";
    cin >> n1 >> n2;

    vector<int> num1, num2;

    for (int i = 0; i < n1; i++)
    {
        int d;
        cin >> d;
        num1.push_back(d);
    }
    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        int d;
        cin >> d;
        num2.push_back(d);
    }

    vector<int> ans = nextGreaterElement(num1, num2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}