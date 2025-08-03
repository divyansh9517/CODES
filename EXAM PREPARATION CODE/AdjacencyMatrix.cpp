#include<bits/stdc++.h>
using namespace std;

void addEdged(vector<vector<int>> &matrix , int i , int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void displayMatrix(vector<vector<int>> &matrix)
{
    int v =matrix.size();
    for(int i = 0 ; i < v; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int v = 4;
    vector<vector<int>> matrix(v,vector<int>(v,0));
    addEdged(matrix,0,1);
    addEdged(matrix,0,2);
    addEdged(matrix,2,3);
    addEdged(matrix,1,2);

    displayMatrix(matrix);
    return 0;
}