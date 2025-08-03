#include<bits/stdc++.h>

using namespace std;

double solve(double x, int n,vector<double>& dp)
{
    if(n == 0)
    {
        return 1.0;
    }
    if(dp[n] != -1.0)
    {
        return dp[n];
    }
    return dp[n]=x*solve(x,n-1,dp);
}

int main(){
    double x = 2.0;
    int n = 10;
    vector<double> dp(n+1,-1.0);
    cout<<solve(x,n,dp);
}