#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0; i<n-2; i++)
        {
            int target = -nums[i], low=i+1, high=n-1;
            while(low < high)
            {
                int sum = nums[low]+nums[high];
                if(sum < target) 
                    low++;
                else if(sum > target)
                    high--;
                else 
                {
                    vector<int> temp = {nums[i], nums[low], nums[high]};
                    if(s.find(temp) == s.end())
                    {
                        ans.push_back(temp);
                        s.insert(temp);
                    }
                    low++;
                    high--;
                }
            }
        }
        return ans;
}

int main()
{
    vector<int> ans={-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(ans);

    for(auto x: res)
    {
        for(auto y: x)
            cout << y <<" ";
        cout << endl;
    }
}
