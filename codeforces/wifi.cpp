#include <bits/stdc++.h>

using namespace std;

#define ld long double

void rec(string s, ld startIdx, vector<ld> &pos, ld curVal)
{
    if(startIdx == s.size())
    {
        pos.push_back(curVal);
        return;
    }
    
    if(s[startIdx] != '?')
    {
        if(s[startIdx] == '+')
            curVal++;
        else 
            curVal--;
        rec(s,startIdx+1,pos,curVal);
    }
    else 
    {
        rec(s,startIdx+1,pos,curVal+1);
        rec(s,startIdx+1,pos,curVal-1);
    }
    
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    ld target = 0;
    for(auto x: s1)
    {
        if(x == '+')
            target++;
        else 
            target--;
    }

    vector<ld> pos;
    rec(s2,0,pos,0);
    ld correctValues=0;
    for(auto x: pos)
    {
        if(x == target)
            correctValues++;
    }

    ld ans=0;
    ans = correctValues/(pos.size());
    cout << setprecision(12)<< ans;

    return 0;
}