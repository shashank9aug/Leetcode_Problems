/*
    We can solve this problem using two methods : 
    - iterative 
    - recurssive
*/

#include<iostream>
using namespace std;

int fib_iterative(int n){
    if(n==0 or n==1){
        return n;
    }

    int n1=0,n2=1,n3=0;
    for(int i=1;i<n;i++){
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    return n3;
}

int fib_recurssive(int n){
    //Base case : 
    if(n==0 or n==1){
        return n;
    }

    //recurssive case : 
    return fib_recurssive(n-1) + fib_recurssive(n-2);
}

int main(){
    int n;
    cin>>n;

    cout<<fib_iterative(n)<<endl;
    cout<<fib_recurssive(n)<<endl;
}