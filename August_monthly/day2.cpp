/*
           : Two sum :

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Output: Because nums[0] + nums[1] == 9, we return [0, 1].


*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>ans(2);

        // for(int i=0;i<nums.size();i++){
            // for(int j=i+1;j<nums.size();j++){
            //     if(nums[i]+nums[j]==target){
            //         ans[0]=i;
            //         ans[1]=j;
            //         break;
            //     }    
            // }
        // }   
        
        //Method - 2 : 
            vector<int>ans(2);
            unordered_map<int, int> mp;
            
            for(int i=0;i<nums.size();i++){
                //check nums[i] presetnt in map or not if not it will insert it as pair of element and index
                if(mp.find(nums[i])==mp.end()){
                    mp[nums[i]]=i;
                }
                
                if(mp.find(target-nums[i])!=mp.end() && i!=mp[target-nums[i]]){
                    ans[0]=i;
                    ans[1]=mp[target-nums[i]];
                    break;
                }
            }
        return ans;
    }
};

int main(){
    vector<int>nums;

    for(int i=0;i<5;i++){
        int d;
        cin>>d;

        nums.push_back(d);
    }

    Solution ob;

    int target;
    cin>>target;

    vector<int>ans = ob.twoSum(nums,target);

    cout<<ans[0]<<" and "<<ans[1];

    return 0;       
}