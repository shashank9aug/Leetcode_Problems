/*
    we have return minimum number of steps required to make string anagram.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int minStepToAnagram(string s, string t)
{
    //O(n) time and space.

    if (s.size() != t.size())
    {
        return 0;
    }

    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {

        if (mp[t[i]] != 0)
        {
            mp[t[i]]--;
        }
        if (mp[t[i]] == 0)
        {
            mp.erase(t[i]);
        }
    }
    int ans = 0;

    for (auto i : mp)
    {
        if (i.second > 0)
        {
            ans += i.second;
        }
    }

    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << minStepToAnagram(s, t) << endl;

    return 0;
}