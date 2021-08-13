#include <iostream>
#include <set>
#include <vector>
#include<algorithm>
using namespace std;

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
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}