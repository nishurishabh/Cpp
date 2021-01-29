// Find the number in an array. If the element does not exist return its closest smaller number
#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> &arr, int tar)
{
    int low = 0, high = arr.size()-1;
    while(low < high)
    {
        int mid = (high+low)/2;
        if(arr[mid] < tar)
            low = mid+1;
        else
            high=mid;
    }

    cout << low <<" - " <<arr[low];
}
int main()
{
    vector<int> arr = {1,5,10,12,13,15,15,20};
    binarySearch(arr,14);
}