#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> dp;
int LCS(string s1, string s2, int m, int n)
{
    if(m<0 || n<0)
        return 0;
    if(dp.find({m,n}) != dp.end())
        return dp[{m,n}];

    if(s1[m] == s2[n])
        dp[{m,n}] = 1+LCS(s1,s2,m-1,n-1);
    else
        dp[{m,n}] = max(LCS(s1,s2,m-1,n), LCS(s1,s2,m,n-1));
    return dp[{m,n}];
}

int main()
{
    string s1 = "ABBCCCDDDDEEEEEE", s2="BACBCCDEEEDD";
    cout << LCS(s1,s2,s1.size()-1,s2.size()-1);
}