// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/ 

#include <bits/stdc++.h>
using namespace std;

int findStartingIndex(vector<int>& nums, int target)
{
    int low=0, high=nums.size()-1;
    while(low < high)
    {
        int mid = (high+low)/2;
        if(nums[mid] < target)
            low = mid+1;
        else
            high=mid;
    }
    
    if(nums[low] != target) return -1;
    return low;
}
    
int findEndingIndex(vector<int> &nums, int target)
{
    int low=0, high=nums.size()-1;
    while(low < high)
    {
        int mid = (high+low)/2 + 1;
        if(nums[mid] > target)
            high=mid-1;
        else
            low=mid;
    }
    if(nums[low] != target) return -1;
    return low;
}

int main()
{
    vector<int> nums = {2,3,7,7,7,8,8,8,8,9,10};
    vector<int> ans(2,-1);
    ans[0] = findStartingIndex(nums,8);
    ans[1] = findEndingIndex(nums,8);
    
    cout << "Starting Index : " << ans[0] <<endl;
    cout << "Ending Index : " << ans[1] <<endl;
}