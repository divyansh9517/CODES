#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int n = arr.size();
    int m = arr[0].size();
    vector<int> ans;
    for(int d = 0 ; d < n+m-1; d++)
    {
        if(d%2 == 0)
        {
            int row = min(d,n-1);
            int col = d - row;

            while(row >= 0 && col < m)
            {
                cout<<arr[row][col];
                row--;
                col++;
            }
        }
        else
        {
            int col = min(d,m-1);
            int row = d - col;
            while(col >= 0 && row < n)
            {
                cout<<arr[row][col];
                col--;
                row++;
            }
        }
    }

    return 0;
}