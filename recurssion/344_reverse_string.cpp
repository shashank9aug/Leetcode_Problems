/*
    we have string given str = "shashank"
    reverse : "knahsahs"

    we have to reverse string using recurssion :

    IBH method :

*/

#include<iostream>
using namespace std;

void reverseStr(string &ip,int start,int end){
    //Base case : 
    if(start>=end){
        return;
    }

    //Induction : 
    swap(ip[start++],ip[end--]);
    reverseStr(ip,start,end); 

    return;
}

void reverseString(string &ip){
    int start=0, end=ip.size()-1;
    reverseStr(ip,start,end);
}

int main(){
    string ip;
    cin>>ip;

    reverseString(ip);

    cout<<ip;

    return 0;
}