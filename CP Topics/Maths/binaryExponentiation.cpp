#include<bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b)
{
    long long res = 1;
    while(b>0)
    {
        if(b & 1) res = res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

long long binpow_rec(long long a, long long b)
{
    if(b == 0) return 1;
    long long res = pow(a,b/2);
    if(b % 2) return res*res*a;
    else return res*res;
}

long long binpowModulo(long long a, long long b, long long m)
{
    a%=m;
    long long res = 1;

    while(b>0)
    {
        if(b & 1) res = res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

int main()
{
    long long a = 12;
    long long b = 12;
    long long m = 1200;
    cout << binpow(a,b) <<endl;
    cout << binpow_rec(a,b) <<endl;
    cout << binpowModulo(a,b,m);
}