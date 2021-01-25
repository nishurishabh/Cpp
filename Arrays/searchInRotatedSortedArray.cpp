#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high=n-1;
        
        // find the pivot point
        while(low < high)
        {
            int mid = (high+low)/2;
            if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid;
        }
        
        int rot = low;
        low = 0, high = n-1;
        
        while(low <= high)
        {
            int mid = (high+low)/2;
            int realMid = (mid+rot) % n;
            
            if(nums[realMid] == target)
                return realMid;
            if(nums[realMid] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return -1;
}

int main()
{
    vector<int> Arr = {4,5,6,7,0,1,2,3};
    cout << search(Arr, 6);
}