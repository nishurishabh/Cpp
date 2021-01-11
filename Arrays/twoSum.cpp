#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &A, int target)
{
    map<int,int> mp; // Maps the values with their index
    vector<int> ans;
    for(int i=0; i<A.size(); i++)
    {
        if(mp.find(target-A[i]) != mp.end())
        {
            ans = {mp[target-A[i]],i};
            break;
        }
        mp[A[i]]=i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(arr,target);
    for(auto x:ans) cout << arr[x] <<" ";
}