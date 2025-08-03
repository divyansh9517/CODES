#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int solve(vector<int>& coin , int amount,vector<int>&dp){
    if(amount == 0)
    {
        return 0;
    }
    
    int mini = INT_MAX;
    if(dp[amount] != -1)
    {
        return dp[amount];
    }
    for(int i = 0 ;i < coin.size(); i++)
    {
        if(amount - coin[i] >= 0)
        {
            int ans = 1+solve(coin,amount-coin[i],dp);
            mini = min(mini,ans);
        }
    }
    return dp[amount]=mini;
}
int main()
{
    int n ;
    cin>>n;

    vector<int> coin(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>coin[i];
    }
    int amount = 11;
    vector<int>dp(amount+1 ,-1);
    cout<<solve(coin,amount,dp);
    return 0;
}