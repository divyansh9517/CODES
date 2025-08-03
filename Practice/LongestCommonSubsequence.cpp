#include<iostream>
#include<vector>
using namespace std;

int solve(string &s1,string &s2,int i,int j)
{
    if(i >= s1.length())
    {
        return 0;
    }
    if(j >= s2.length())
    {
        return 0;
    }
    int ans;

    if(s1[i] == s2[j])
    {
        ans = 1+solve(s1,s2,i+1,j+1);
    }
    else{
        ans = max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    
    return ans;
}
// memoaization
int solveME(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
{
    if(i >= s1.length())
    {
        return 0;
    }
    if(j >= s2.length())
    {
        return 0;
    }

    // step 3 check there is any element already present in dp array
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans;

    if(s1[i] == s2[j])
    {
        ans = 1+solveME(s1,s2,i+1,j+1,dp);
    }
    else{
        ans = max(solveME(s1,s2,i+1,j,dp),solveME(s1,s2,i,j+1,dp));
    }
    // step 2 : store ans in dp array
    dp[i][j] = ans;
    return dp[i][j];
}

// by tabulation
int solveTab(string s1 , string s2)
{
    vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1,0));

    for(int i = s1.length()-1 ; i>= 0 ; i--)
    {
        int ans = 0;
        for(int j = s2.length()-1; j >= 0 ; j--)
        {
            if(s1[i] == s2[j])
            {
                ans = 1+dp[i+1][j+1];
            }
            else
            {
                ans = 0+max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j]=ans;
        }
        
    }
    return dp[0][0];
}

// space optimized
int solveTabSO(string s1 , string s2)
{
    //vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1,0));
    vector<int> currRow(s2.length()+1,0);
    vector<int> nextRow(s2.length()+1,0); 

    for(int i = s1.length()-1 ; i>= 0 ; i--)
    {
        int ans = 0;
        for(int j = s2.length()-1; j >= 0 ; j--)
        {
            if(s1[i] == s2[j])
            {
                ans = 1+nextRow[j+1];
            }
            else
            {
                ans = 0+max(currRow[j+1],nextRow[j]);
            }
            currRow[j]=ans;
        }
        nextRow=currRow;
    }
    return nextRow[0];
}


int main()
{
    string s1 = "abcde";
    string s2 = "abd";

    // memoaization

    // step 1 : - create and 2d-array of n+1 and m+1 size

    vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1,-1));


    cout<<"Solved by Memoaization: - "<<solveTabSO(s1,s2);
    return 0;
}
