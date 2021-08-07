/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order. 

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

// #include<iostream>
// #include<vector>
// #include<string>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void permute(vector<int>&ip,int i,int n,vector<vector<int>>&ans){
        //Base case : 
        if(i==(n-1)){
            ans.push_back(ip);
            return;
        }

        //Rec case : 
        for(int j=i;j<n;j++){
            swap(ip[i],ip[j]);
            permute(ip,i+1,n,ans);
            //Back track : to avoid duplicates : 
            swap(ip[i],ip[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permute(nums,0,nums.size(),ans);
        
        return ans;   
    }
};


int main(){
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }
    Solution ob;
    vector<vector<int>>ans=ob.permute(nums);

    for(int i=0;i<ans.size();i++){
        cout<<ans[0][i]<<" ";
    }

    return 0;
}