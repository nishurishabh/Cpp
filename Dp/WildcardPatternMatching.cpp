// https://www.techiedelight.com/wildcard-pattern-matching/


#include<bits/stdc++.h>
using namespace std;

bool wildcardPatternMatching(string str, string pattern)
{
    int n = str.size();
    int m=pattern.size();

    bool dp[n+1][m+1];
    dp[0][0]=true;

    for(int j=1; j<=m; j++)
    {
        if(pattern[j-1] == '*')
            dp[0][j]=dp[0][j-1];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(pattern[j-1] == '?' || str[i-1] == pattern[j-1])
                dp[i][j]=dp[i-1][j-1];
            else if(pattern[j-1] == '*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            else dp[i][j]=false;
        }
    }

    return dp[n][m];
}

int main()
{
    string str="xyxzzxy",pattern="x?x*y";
    cout << wildcardPatternMatching(str,pattern);
}