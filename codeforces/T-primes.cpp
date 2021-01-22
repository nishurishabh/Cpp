#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll, ll> um;
ll N = 10000000;
void sieveOfErosthenes()
{
    bool arr[N];
    memset(arr, true, sizeof(arr));
    for(ll p=2; p*p < N; p++)
    {
        if(arr[p] == true)
        {
            for(ll i=p*p; i < N; i+=p)
                arr[i]=false;
        }
    }

    for(ll i=0; i<N; i++)
    {
        if(arr[i] == true)
        {
            um[i*i]=1;
        }
    }
   
}

int main()
{
    vector<ll> a;
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        a.push_back(x);
    }
    sieveOfErosthenes();
    for(auto x: a)
    {
        if(x == 1)
        {
            cout << "NO" <<endl;
            continue;
        }
        if(um.find(x) != um.end())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}