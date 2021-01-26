#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> m;
    for(auto x:strs) {
        string temp = x;
        sort(x.begin(), x.end());
        m[x].push_back(temp);
    }
    
    vector<vector<string> > ans;
    for(auto x:m) ans.push_back(x.second);
    return ans;
}

int main()
{
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto x: ans)
    {
        for(auto y: x)
            cout << y <<" ";
        cout << endl;
    }
}