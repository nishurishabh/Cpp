// https://leetcode.com/problems/rotate-image/
#include<bits/stdc++.h>

using namespace std;

void rotateClockwise(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++) {
            for(int j=i+1; j<matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
}

void rotateAntiClockwise(vector<vector<int>> &matrix)
{
    for(auto &x: matrix)
        reverse(x.begin(), x.end());
    

    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=i+1; j<matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> mat{{1,2,3}, {4,5,6}, {7,8,9}};
    rotateAntiClockwise(mat);
    for(auto x: mat)
    {
        for(auto y: x)
            cout << y <<" ";
        cout<<endl;
    }
}