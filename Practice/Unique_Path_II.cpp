#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
{
    if(i < 0 || j < 0) return 0;  // First check bounds

    if(obstacleGrid[i][j] == 1) return 0;

    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int up = solve(i - 1, j, obstacleGrid, dp);
    int left = solve(i, j - 1, obstacleGrid, dp);

    return dp[i][j] = up + left;
}

int solveTab(int m, int n, vector<vector<int>> &obstacleGrid)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue; 
            }

            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if(i > 0)
                up = dp[i-1][j];
            if(j > 0)
                left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    

    cout << solveTab(m, n, obstacleGrid) << endl;
}
