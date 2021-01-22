#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1, maxArea=0;
        
        while(low < high)
        {
            maxArea = max(maxArea, min(height[low], height[high])*(high-low));
            if(height[low] < height[high]) low++;
            else high--;
        }
        return maxArea;
}

int main()
{
    vector<int> A{1,8,6,2,5,4,8,3,7};
    cout << maxArea(A);
    return 0;
}