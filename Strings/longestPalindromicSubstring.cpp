#include<bits/stdc++.h>

using namespace std;


string longestPalindrome(string s) {
    int n=s.size(), start=0, len=1;
    if(n<2) return s;
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    
    // substring of length 1
    for(int i=0; i<n; i++)
    {
        dp[i][i]=true;
    }
    
    // substring of lenght 2
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == s[i+1]) {
            start=i;
            len=2;
            dp[i][i+1]=true;
        }
    }
    
    // substrings greater than 2
    for(int k=3; k<=n; k++)
    {
        for(int i=0; i<= n-k; i++)
        {
            int j=k+i-1;
            if(dp[i+1][j-1] && s[i] == s[j])
            {
                dp[i][j]=true;
                start=i;
                len=k;
            }
        }
    }
    return s.substr(start, len);
}

int main()
{
    cout << longestPalindrome("ABDCBCDBDCBBC");
}