/*
        Subset-II
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]] 

*/

#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    set<vector<int>>s;   
    void printSubset(vector<int>nums,vector<int>op,vector<vector<int>>&ans){
        //Base case : 
        if(nums.size()==0){
            if(s.find(op)==s.end()){
                s.insert(op);
                ans.push_back(op);
            }
            return;
        }
        
        //IP-OP
        vector<int>op1=op;
        vector<int>op2=op;
        
        op2.push_back(nums[0]);
        
        nums.erase(nums.begin()+0);
        
        printSubset(nums,op1,ans);
        printSubset(nums,op2,ans);
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        sort(nums.begin(),nums.end());
        printSubset(nums,op,ans);
        // sort( ans.begin(), ans.end() );
        // ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;   
    }
    // [[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
};

int main(){
    vector<int>nums;

    for(int i=0;i<3;i++){
        int d;
        cin>>d;

        nums.push_back(d);
    }

    Solution ob;


    vector<vector<int>>ans = ob.subsetsWithDup(nums);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<endl;
        }
    }

    return 0;       
}