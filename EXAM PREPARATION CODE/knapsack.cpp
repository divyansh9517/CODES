#include<bits/stdc++.h>
using namespace std;
int solve(int wt[],int profit[] ,int capacity , int ind,int n,vector<vector<int>> dp)
{
    //int n = wt.size();
    if(ind == n-1)
    {
        if(wt[ind] <= capacity)
        {
            return profit[ind];
        }
        else{
            return 0;
        }
    }
    if(dp[ind][capacity] != -1)
    {
        return dp[ind][capacity];
    }

    int inc = 0;
    if(wt[ind] <= capacity)
    {
        inc = profit[ind] + solve(wt,profit,capacity - wt[ind],ind+1,n,dp);
    }
    int not_inc = 0 + solve(wt,profit,capacity,ind+1,n,dp);
    return dp[ind][capacity]=max(inc,not_inc);
}

int solveTab(int wt[],int profit[] ,int capacity ,int n)
{
    vector<vector<int>> dp(capacity+1,vector<int>(n+1,0));

    for(int i = 0 ; i <=  capacity ; i++)
    {
        for(int j = n-1 ; j>=0 ;j--)
        {
            int inc = 0;
            if(wt[j] <= i)
            {           
                inc = profit[j] + dp[i - wt[j]][j+1];
            }
            int not_inc = 0 + dp[i][j+1];
            dp[i][j]=max(inc,not_inc);
        }
    }
    
    
    return dp[capacity][0];
}


int main()
{
    int wt[] = {10,20,30};
    int profit[] = {60,100,120};
    int capacity = 50;
    int n  = 3;
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
    cout<<solveTab(wt,profit,capacity,n)<<endl;
    return 0; 

}