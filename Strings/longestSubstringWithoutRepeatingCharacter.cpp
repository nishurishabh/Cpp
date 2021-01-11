#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
        vector<int> lookup(256,-1);
        int start=-1, l=0,ans=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(lookup[s[i]] >= start) start=lookup[s[i]];
            lookup[s[i]]=i;
            ans=max(ans, i-start);
        }
        return ans;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}