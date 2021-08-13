/*
Input: s = "is2 sentence4 This1 a3"

Output: "This is a sentence"

Explanation: Sort the words in s to their original positions 
"This1 is2 a3 sentence4",
then remove the numbers.

    Basically we have to sort the strings according to given index position value and delete that number.

*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

string sortString(string str){
    string word;
    //as constraints of question str will have 1 to 9 no words
    vector<string>v(10);

    //iterate over string :
    for(int i=0;i<str.size();i++){
        //if str[i] will be digit we have to store its corresponding string at v[digit]
        if(str[i]>=48 and str[i]<=57){
            v[str[i]-48]=word+" ";
            word="";
            i++;
        }
        word+=str[i];
    }

    string ans="";
    for(string it:v){
        ans+=it;
    }
    ans.pop_back();
    return ans;
}

int main(){
    string str;
    getline(cin,str);

    cout<<sortString(str)<<endl;
}