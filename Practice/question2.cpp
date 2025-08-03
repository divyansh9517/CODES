#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> & mat){
    int row = mat.size();
    int col = mat[0].size();
    int prod =1;

    for(int i = 0; i < row ; i++)
    {
        for(int j = 0 ; j < col ;j++)
        {
            if(i == j && mat[i][j] % 2 == 1)
            {
                prod *= mat[i][j];
            }
            if(i == j && mat[i][j] % 2 == 0)
            {
                return 0;
            }
        }
    }
    return prod;

}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,0,6},{7,8,9}};
    cout<<solve(mat);
}