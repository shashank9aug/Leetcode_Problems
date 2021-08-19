/*
    PS : Max sum of largest congtiguous subarray

    i/p : 2 -1 -3 4 -1 2 1 -5 4
    o/p : 6  => [4,-1,2,1,-5,4]

    Approach : 
    - Sliding window 
    - Kadane's algorithm
    - Brute force    

*/

#include <iostream>
#include <climits>
using namespace std;


//Kadane's Algorithm : 
int maxSubarray(int arr[], int n)
{
    int mx = INT_MIN;
    int mx_end = 0;

    for (int i = 0; i < n; i++)
    {
        mx_end = max(arr[i], mx_end + arr[i]);

        if (mx < mx_end)
        {
            mx = mx_end;
        }
    }
    return mx;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Max contiguous subarray sum : " << maxSubarray(arr, n) << endl;

    return 0;
}