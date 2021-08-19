#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
 
/* 
vector<vector<int>> threeSum(vector<int> &nums)
{
    //Brute force :
    int size = nums.size();

    if (size == 0 or size < 3)
    {
        return {};
    }
    //set stores all unique elements
    set<vector<int>> s;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
}
*/
//O(n^2) : Best optimal approach  : Two pointer approach
vector<vector<int>> threeSum(vector<int> &arr)
{
    int n = arr.size();

    if (n < 3)
        return {};
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                res.push_back({arr[i], arr[j], arr[k]});

                while (j < k && arr[j] == arr[j + 1])
                    j++;
                while (j < k && arr[k] == arr[k - 1])
                    k--;
                j++;
                k--;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter no of elements : ";
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    vector<vector<int>> ans = threeSum(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); i++)
        {
            cout << ans[i][j]<<" ";
        }
    }

    return 0;
}