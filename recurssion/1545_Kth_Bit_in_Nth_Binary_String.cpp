#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int KthBit(int n,int k){
         //Base case :
        if(n==1 and k==1){
            return 0;
        }
        
        int mid=pow(2,n)/2;
        
        if(k==mid){
            return 1;
        }
        else if(k>mid){
            return !(KthBit(n-1,((2*mid) - k)));
        }
        else{
            return KthBit(n-1,k);
        }
    }
    
    char findKthBit(int n, int k) {
        int ans=KthBit(n,k);   
        char s = ans + '0';
        
        return s;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    Solution ob;
    cout<<"Kth bit in nth binary string : "<<ob.findKthBit(n,k)<<endl;

    return 0;
}