#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// solve using recursion
int solve(string &s1,string &s2,int i, int j)
{
    if(i >= s1.length())
    {
        return 0;
    }
    if(j >= s2.length())
    {
        return 0;
    }

    int ans = 0;
    if(s1[i] == s2[j])
    {
        ans = 1+solve(s1,s2,i+1,j+1);
    }
    else{
        ans = 0+max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    
    return ans;
}

//solve using memoaization

int solveME(string &s1,string &s2,int i, int j,vector<vector<int>> &dp)
{
    if(i >= s1.length())
    {
        return 0;
    }
    if(j >= s2.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if(s1[i] == s2[j])
    {
        ans = 1+solveME(s1,s2,i+1,j+1,dp);
    }
    else{
        ans = 0+max(solveME(s1,s2,i+1,j,dp),solveME(s1,s2,i,j+1,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}

// solve by tabulation

int solveTab(string s1, string s2)
{
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));

    for(int i = s1.length()-1 ; i>= 0 ;i--)
    {
        int ans = 0;
        for(int j = s2.length()-1 ; j >= 0 ; j--)
        {
            
            if(s1[i] == s2[j])
            {
                ans = 1+dp[i+1][j+1];
            }
            else{
                ans = max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
        
    }
    return dp[0][0];

}

int main()
{
    string s1 = "bbbab";
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    vector<vector<int>> dp(s1.length()+1,vector<int>(s1.length()+1,-1));
    cout<<solveME(s1,s2,0,0,dp)<<endl;
    return 0;
    
   
}