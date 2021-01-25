// http://codeforces.com/problemset/problem/115/A

#include <bits/stdc++.h>
using namespace std;
int N = 2001;
vector<vector<int>> adj;
vector<bool> vis;

void addEdge(int par, int child)
{
    adj[par].push_back(child);
}

void dfs(int x, int curLevel, int &height)
{
    if(vis[x] == true)
        return;
    vis[x]=true;
    if(curLevel > height)
        height = curLevel;
    for(auto node:adj[x])
    {
        dfs(node, curLevel+1, height);
    }
}

int main()
{
    adj.resize(N);
    vis.resize(N,false);
    int n;
    cin>>n;
    vector<int> a;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    vector<int> toStart;
    for(int i=0; i<n; i++)
    {
        if(a[i] == -1)
        {
            toStart.push_back(i+1);
            continue;
        }
        addEdge(a[i],i+1);
    }

    int ans = 0;
    for(auto x: toStart)
    {
        int h = 0;
        dfs(x,1,h);
        ans = max(ans, h);
    }

    cout << ans;
    return 0;
}