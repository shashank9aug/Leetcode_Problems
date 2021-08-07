/*
Input: x = 121
Output: true
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        return (x==rotate(x));
    }
    
    
    long long rotate(int x){
        long long result=0;
            
        while(x>0){
            result=result*10 + x%10;
            x=x/10;
        }
            
        return result;
    }
};


int main(){
    int num;
    cin>>num;

    Solution ob;
    bool ans=ob.isPalindrome(num);

    if(ans){
        cout<<"Pallindrome number.";
        
    }
    else{
        cout<<"Non-pallindromic number.";
    }
    return 0; 
}