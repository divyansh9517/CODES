#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long solve(int i,int j,vector<vector<char>> &grid,vector<vector<long long>>&dp)
{
    if(i < 0 || j < 0 || grid[i][j] == '*')
    {
        return 0;
    }
    if(i == 0 && j == 0)
    {
        return grid[0][0] == '.' ? 1 : 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    long long up = solve(i-1,j,grid,dp);
    long long left = solve(i,j-1,grid,dp);

    return dp[i][j] = (up + left)%MOD;
    
}

long long  gridPath(int n,vector<vector<char>>& grid)
{
    vector<vector<long long>> dp(n,vector<long long>(n,-1));
    return solve(n-1,n-1,grid,dp);
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<gridPath(n,grid);
}