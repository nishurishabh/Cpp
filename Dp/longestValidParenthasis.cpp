#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {
        int maxValPar = 0;
        vector<int> dp(s.size(),0);
        
        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                    dp[i] = (i>=2 ? dp[i-2] : 0) + 2;
                
                else if(i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(')
                        dp[i] = dp[i-1]+2+(i-dp[i-1]-2 >=0 ? dp[i-dp[i-1]-2] : 0);
                
            }
            maxValPar = max(maxValPar, dp[i]);
        }
        
        return maxValPar;
    }

int main()
{
    string s = "(())()(()";
    cout << longestValidParentheses(s);
}