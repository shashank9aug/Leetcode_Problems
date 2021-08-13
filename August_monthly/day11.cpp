/*
    we will have to store arr[i] with its frequency.
    and if arr[i] and 2*arr[i] exist in map then reduce their frequency by one
    and check if any element will have frequency >0 then return false;
    else return true  

$ ./a.exe
4
4 -2 2 -4
Pair exist.

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

bool canReorderDoubled(vector<int> &arr)
{
    //unordered map to count to no for pairing
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    //sort the array : to search doubled element next to arr[i] element
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] != 0 and mp[2 * arr[i]] != 0)
        {
            mp[arr[i]]--;
            mp[2 * arr[i]]--;
        }
    }

    //check if mp have any element frequency >0 return false else true
    for (auto i : mp)
    {
        if (i.second > 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int>ip;
    int d;
    for(int i=0;i<n;i++){
        cin>>d;
        ip.push_back(d);
    }
    bool ans=canReorderDoubled(ip);

    if(ans){
        cout<<"Pair exist.";
    }
    else{
        cout<<"Pair not exist.";
    }

    return 0;
}