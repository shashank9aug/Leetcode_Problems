/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

/*
Approach-1 : O(n^2)
    store ith string's char in map and iterate over other strings and check 
    if they found put them together and erase that found match.

*/
vector<vector<string>>groupAnagram1(vector<string>&str){
    vector<vector<string>>ans;
    unordered_map<char,int>mp;

    for(int i=0;i<str.size();i++){
        //map frequency of 1st... string char
        for(int j=0;j<str[i].size();j++){
            mp[str[i][j]]++;
        }
        //check for other corresponding chars.
        for(int j=0;j<str.size();i++){

        }

    }
} 

/*
    Approach : 2 (using sorting) : O(Nklogk)  K :max length of array of string 
*/

vector<vector<string>> groupAnagram_2(vector<string>&str){
    vector<vector<string>>ans;
    unordered_map<string,vector<string>>mp;

    //take each string and sort it and check for it's correspondance
    string temp;
    for(int i=0;i<str.size();i++){
        temp=str[i];
        sort(str[i].begin(),str[i].end());
        //temp = eat  ->  sort(eat) => aet 
        //mp[aet]->eat 
        mp[str[i]].push_back(temp);
    } 

    for(auto it : mp){
        ans.push_back(it.second);
    }

    return ans;
}

//Aproach : 3 : O(NK)

string sortStr(string str){
    //sort according to lexicographical order 
    int n=str.size();
    //assign all small letter as 0 initially
    int count[26]={0};

    for(char it:str){
        // ate = > aet
        count[it-'a']++;
    }
    string s;
    for(int i=0;i<26;i++){
        s+=string(count[i],i+'a');
    }

    return s;
}

vector<vector<string>>groupAnagram_3(vector<string>&str){
    vector<vector<string>>ans;
    unordered_map<string,vector<string>>mp;

    int n=str.size();

    while(n>=0){
        mp[sortStr(str[n])].push_back(str[n]);
        n--;
    }

    //update the ans vector
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}




int main(){
    vector<string>str;
    for(int i=0;i<5;i++){
        string s;
        cin>>s;
        str.push_back(s);
    }

    vector<vector<string>>ans = groupAnagram_3(str);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }

    }
    return 0;
}
