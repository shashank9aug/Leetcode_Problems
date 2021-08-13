/*
    Input: s = "anagram", t = "nagaram"
    Output: true

    Input: s = "rat", t = "car"
    Output: false
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//O(n^2)
bool validAnagram(string s, string t)
{
    //length must be same for anagrams
    if (s.size() != t.size())
    {
        return false;
    }

    bool visited[t.size()];
    bool isAnagram = false;
    for (int i = 0; i < s.size(); i++)
    {
        isAnagram = false;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j] && !visited[j])
            {
                visited[j] = true;
                isAnagram = true;
                break;
            }
        }
        if (!isAnagram)
        {
            break;
        }
    }

    return isAnagram;
}

//TC : O(n) SC: O(n)

bool isAnagram(string s, string t)
{
    //O(n) time and space.

    if (s.size() != t.size())
    {
        return false;
    }

    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]--;
        if (mp[t[i]] == 0)
        {
            mp.erase(t[i]);
        }
    }

    if (mp.size() != 0)
    {
        return false;
    }

    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;

    // bool ans = validAnagram(s, t);
    bool ans = isAnagram(s, t);

    if (ans)
    {
        cout << "They are valid anagrams" << endl;
    }
    else
    {
        cout << "Not valid anagrams" << endl;
    }
    return 0;
}