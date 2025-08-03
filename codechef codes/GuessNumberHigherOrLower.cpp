#include<bits/stdc++.h>
#include<vector>
using namespace std;
int solve(int s,int e)
{

    if(s >= e)
    {
        return 0;
    }
    int ans = INT_MAX;
    for( int i = s;  i <=e;i++)
    {
        ans = min(ans,i+max(solve(0,i-1),solve(i+1,e)));
    }
    return ans;
}

// by tab 
int solveT(int n)
    {
        vector<vector<int>> dp(n+2,vector<int>(n+1,0));

        for(int st = n-1 ; st >= 1;st--)
        {
            for(int ed = 1; ed <= n ;ed++)
            {
                if(st >= ed)
                {
                    continue;
                }
                int ans  = INT_MAX;

                for(int  i=   st ; i <=  ed ;i++)
                {
                    ans = min(ans, i+max(dp[st][i-1],dp[i+1][ed]));
                }
                dp[st][ed] = ans;
            }
        }
        return dp[1][n];
    }
int main()
{
    int n = 2;
    cout<<solveT(n);
    return 0;
}