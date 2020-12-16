// CPP program to find LCA in a tree represented 
// as parent array. 
#include <bits/stdc++.h> 
using namespace std; 

long long MOD = 1000000007;

long long solve(int n, int *a)
{
    long long sum=0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(__gcd(a[i], a[j]) == 1)
            {
                long long t = (a[i]*a[j])%MOD;
                sum=(sum+t)%MOD;
            }
            
        }
    }
    return sum;
}

int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout << solve(n,arr);
    } 
} 


// 7
// 1 2
// 1 4
// 2 4
// 2 5
// 3 5
// 3 6
// 5 7
// 6 7

// 7
// 4 7
// 1 4
// 2 4
// 2 5
// 3 5
// 3 6
// 5 7
// 6 7