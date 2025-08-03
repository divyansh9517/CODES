#include<bits/stdc++.h>

using namespace std;

// solved by recursion
int solve(string &a,string &b,int i,int j)
{
    if(i == a.length())
    {
        return b.length()-j;
    }
    if(j == b.length())
    {
        return a.length()-i;
    }
    int ans=0;
    if(a[i] == b[j])
    {
        ans = 0+solve(a,b,i+1,j+1);
    }
    else{
        int replace = 1+solve(a,b,i+1,j+1);
        int insert = 1+solve(a,b,i,j+1);
        int remove = 1+solve(a,b,i+1,j);
        ans = min(replace,min(insert,remove));
    }
    return ans;
}

// solve using memoaization
int solveME(string &a,string &b,int i,int j,vector<vector<int>> &dp)
{
    if(i == a.length())
    {
        return b.length()-j;
    }
    if(j == b.length())
    {
        return a.length()-i;
    }
    int ans=0;
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(a[i] == b[j])
    {
        ans = 0+solveME(a,b,i+1,j+1,dp);
    }
    else{
        int replace = 1+solveME(a,b,i+1,j+1,dp);
        int insert = 1+solveME(a,b,i,j+1,dp);
        int remove = 1+solveME(a,b,i+1,j,dp);
        ans = min(replace,min(insert,remove));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

// solve by tab

int solveTab(string a,string b)
{
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
    for(int col = 0 ; col <= b.length() ; col++)
    {
        dp[a.length()][col] = b.length()-col;
    }

    for(int row = 0 ; row <= a.length() ; row++)
    {
        dp[row][b.length()] = a.length()-row;
    }

    for(int i= a.length()-1;i>=0;i--)
    {
        for(int j = b.length()-1 ; j >=0 ;j--)
        {
            int ans = 0;
            if(a[i] == b[j])
            {
                ans = 0+dp[i+1][j+1];
            }
            else{
                int replace = 1+dp[i+1][j+1];
                int insert = 1+dp[i][j+1];
                int deletee = 1+dp[i+1][j];
                ans = min(replace,min(insert,deletee));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//space optimization
int solveTabSO(string a,string b)
{
    vector<int> curr(a.length()+1,0);
    vector<int> next(a.length() +1,0);
    // for(int col = 0 ; col <= b.length() ; col++)
    // {
    //     dp[a.length()][col] = b.length()-col;
    // }

    for(int row = 0 ; row <= a.length() ; row++)
    {
        next[row] = a.length()-row;
    }


    for(int j = b.length()-1 ; j >=0 ;j--)
    {
        curr[a.length()]=b.length()-j;
        for(int i= a.length()-1;i>=0;i--)
        {
        
            int ans = 0;
            if(a[i] == b[j])
            {
                ans = 0+next[i+1];
            }
            else{
                int replace = 1+next[i+1];
                int insert = 1+next[i];
                int deletee = 1+curr[i+1];
                ans = min(replace,min(insert,deletee));
            }
            curr[i] = ans;
        }
        next = curr;
    }
    return next[0];
}


int main()
{
    string s1 = "horse";
    string s2 = "ros";

    vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1,-1));
    cout<<solveTabSO(s1,s2);
    return 0;
}