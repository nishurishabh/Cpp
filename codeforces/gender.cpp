#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char,int> mp;
    int ans=0;
    for(auto x: s)
    {
        if(mp.find(x) == mp.end())
            ans++;
        mp[x]=1;
    }
    
    if(ans%2 == 0)
        cout << "CHAT WITH HER!";
    else 
        cout << "IGNORE HIM!";
    
    return 0;
}