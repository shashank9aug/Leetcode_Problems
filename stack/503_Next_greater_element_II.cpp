/*
    Leetcode : 503.Next Greater Element-II
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
    Intution : 
*/

vector<int> nextGreaterII(vector<int>ip){
    int n=ip.size();
    vector<int>ans(n,-1);
    stack<int>st;
    
    for(int i=(2*n-1);i>=0;i--){
        while(!st.empty() and st.top()<=ip[i%n]){
            st.pop();
        }
        // if(i<n){
        //     if(st.empty()==false){
        //         ans[i%n]=st.top();
        //     }
        //     else{
        //         ans[i%n]=-1;
        //     }
        // }
        if ( !st.empty() ){
            ans[ i % n ] = st.top();
        }    
        st.push(ip[i%n]);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;

    vector<int>ip;

    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        ip.push_back(d);
    }

    vector<int>ans=nextGreaterII(ip);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}