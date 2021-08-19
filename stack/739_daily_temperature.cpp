/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//we can use nested for loop to calculate the temperature hike
// O(N^2)

/* o(n) with extra space
vector<int> dailyTemperatures(vector<int>& t) {
    vector<int> ans(t.size(),0);
    stack<int>st;
    //store all temperatures in stack : 
    for(int i=t.size()-1;i>=0;i--){
        st.push(t[i]);
    }

    for(int i=0;i<t.size();i++){
        
        if(t[i]<st.top() and i<t.size()-1){
            ans[i]=1;
        }
        st.pop();
        while(st.top()<t[i]){
            st.top();
        }

    }

}
*/

/*
    Traverse from end of temperature vector and use another vector to store index.
    store index of temp array untill we get next greater temperature.
*/
/*
vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> st;
    vector<int> ans(T.size(), 0);

    st.push_back(T.size() - 1);
    for (int i = T.size() - 2; i >= 0; i--)
    {
        while (!st.empty() && T[i] >= T[st.back()])
            st.pop_back();

        if (!st.empty() && T[i] < T[st.back()])
            ans[i] = st.back() - i;

        st.push_back(i);
    }

    return ans;
}
*/

vector<int> dailyTemperatures(vector<int>& T) {
	int n = T.size();
	stack<int> s;
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		while (!s.empty() and T[s.top()] < T[i]) {
			int j = s.top(); s.pop();
			ans[j] = i - j;
		}
		s.push(i);
	}
	return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }

    vector<int> ans = dailyTemperatures(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}