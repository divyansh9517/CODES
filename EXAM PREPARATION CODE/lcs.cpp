#include<bits/stdc++.h>
using namespace std;
int solve(string s1,string s2,int i, int j,vector<vector<int>>&dp)
{
    if(i >= s1.length())
    {
        return 0;
    }
    if(j >= s2.length())
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if(s1[i] == s2[j])
    {
        ans = 1+solve(s1,s2,i+1,j+1,dp);
    }
    else{
        ans = max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    }
    return dp[i][j]=ans;

}
int main()
{
    string s1 = "abcd";
    string s2 = "dcabc";

    vector<vector<int>>dp(s1.size()+1 , vector<int>(s2.size()+1,-1));

    cout<<solve(s1,s2,0,0,dp)<<endl;
}