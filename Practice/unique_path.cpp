#include<bits/stdc++.h>
using namespace std;
int solve(int i ,int j,vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
    {
        return 1;
    }
    if(i < 0 || j < 0)
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = solve(i-1,j,dp);
    int left = solve(i,j-1,dp);

    return dp[i][j] = up + left;
}

int solveTab(int m,int n)
{
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i =0 ; i< m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int left = 0;
            int up = 0;
            if(i > 0)
            {
                up = dp[i-1][j];
            }
            if(j > 0)
            {
                left = dp[i][j-1];
            }

            dp[i][j] = left+up;
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int i = 3;
    int j = 7;
    vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
    cout<<solve(i-1,j-1,dp)<<endl;
    cout<<"Solve by tabulation : - "<<solveTab(i,j);
}