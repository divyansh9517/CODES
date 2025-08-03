#include<bits/stdc++.h>

using namespace std;

int solve(string &s1,string &s2,int i,int j)
{
    if(i >= s1.size())
    {
       return 0;
    }
    if(j >= s2.size())
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
// by memoaization
int solveMEM(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
{
    if(i >= s1.size())
    {
       return 0;
    }
    if(j >= s2.size())
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
        ans = 1+solveMEM(s1,s2,i+1,j+1,dp);
    }
    else{
        ans = 0+max(solveMEM(s1,s2,i+1,j,dp),solveMEM(s1,s2,i,j+1,dp));
    }
    return dp[i][j] = ans;
}




int revCheck(string &s)
{
    string s1 = s;
    
    reverse(s.begin(),s.end());
    vector<vector<int>> dp(s.size()+1 ,vector<int>(s1.size()+1,-1));
    return solveMEM(s,s1,0,0,dp);
}
int main()
{
    string a = "mbadm";
    int len_rev = revCheck(a);
    cout<<a.length()- len_rev;
    return 0;
}