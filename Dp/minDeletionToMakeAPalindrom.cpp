#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> lookup;
int minDeletions(string s, int i, int j)
{
    if(i>j) return 0;
    if(lookup.find({i,j}) != lookup.end())
        return lookup[{i,j}];
    if(s[i] == s[j])
    {
        int res = minDeletions(s,i+1,j-1);
        lookup[{i,j}]=res;
    }
    else
    {
        int res = 1+min(minDeletions(s,i+1,j), minDeletions(s,i,j-1));
        lookup[{i,j}] = res;
    }
    return lookup[{i,j}];
}


int main()
{
    string s="ACBCDBAA";
    int size=s.size();
    cout<< minDeletions(s,0,size-1);
}