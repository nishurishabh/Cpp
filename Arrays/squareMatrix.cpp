#include <bits/stdc++.h>
using namespace std;

void generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int>(n));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int j=1;
        
        while(top <= bottom && left <= right) {
            for(int i=left; i<=right; i++) mat[top][i] = j++; top++;
            for(int i=top; i<=bottom; i++) mat[i][right] = j++; right--;
            for(int i=right; i>=left; i--) mat[bottom][i] = j++; bottom--;
            for(int i=bottom; i>=top; i--) mat[i][left] = j++; left++;
        }
        
        for(auto x: mat)
        {
            for(auto y: x)
                cout << y <<" ";
            cout << endl;
        }
}

int main()
{
    generateMatrix(10);
}