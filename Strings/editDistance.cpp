#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int editDistance(string s1, string s2, int m, int n, vector<vector<int>> &dp)
{
    if(min(m,n) == 0) return max(m,n);
    
    if(dp[m][n] != -1) return dp[m][n];
    if(s1[m-1] == s2[n-1])
        dp[m][n] = editDistance(s1,s2,m-1,n-1,dp);
    else
    {
        dp[m][n] =  1+min(
                        min(editDistance(s1,s2,m,n-1,dp), editDistance(s1,s2,m-1,n,dp)),   // Insertion and Deletion Respectively
                        editDistance(s1,s2,m-1,n-1,dp)                                // Replacement of a char
                    );
    }
    return dp[m][n];
}

int main()
{
    string s1 = "intention", s2 = "execution";
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
    cout << editDistance(s1,s2,m,n,dp);
}