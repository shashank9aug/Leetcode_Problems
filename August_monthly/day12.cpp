/*
    Group Anagram problem : 

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [
        ["bat"],
        ["nat","tan"],
        ["ate","eat","tea"]
    ]

$ ./a.exe
Enter vector of string length : 6
eat tea tan ate nat bat
eat tea ate 
bat
tan nat


*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string> &str)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    //take each string and sort it and check for it's correspondance
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        temp = str[i];
        sort(str[i].begin(), str[i].end());
        //temp = eat  ->  sort(eat) => aet
        //mp[aet]->eat
        mp[str[i]].push_back(temp);
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter vector of string length : ";
    cin>>n;

    vector<string>st(n,"");

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st[i]=s;
    }

    vector<vector<string>>ans=groupAnagrams(st);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}