// http://codeforces.com/problemset/problem/285/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   vector<ll> A;
   ll n;
   cin>>n;
   for(ll i=0; i<n; i++)
   {
       ll x;
       cin>>x;
       A.push_back(x);
   }

    sort(A.begin(), A.end());
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        ans+=abs(A[i-1]-i);
    }
    cout << ans;
    return 0;
}