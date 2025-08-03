#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int curr,int prev,int n)
{
    if(curr >n)
    {
        return 0;
    }

    int inc = 0;
    //prev == -1 bhul sakty ho 

    if(prev == -1 || arr[curr] > arr[prev])
    {
        inc =1+solve(arr,curr+1,curr,n);
    }
    int exc = 0+solve(arr,curr+1,prev,n);
    int ans = max(inc,exc);
    return ans;
}


// Now applying memoaization
int solveMe(int arr[],int curr,int prev,int n, vector<vector<int>> &dp)
{
    if(curr >=n)
    {
        return 0;
    }

    int inc = 0;
    //prev == -1 bhul sakty ho 
    if(dp[curr][prev+1] != -1)
    {
        return dp[curr][prev+1];
    }

    if(prev == -1 || arr[curr] > arr[prev])
    {
        inc =1+solveMe(arr,curr+1,curr,n,dp);
    }
    int exc = 0+solveMe(arr,curr+1,prev,n,dp);
    int ans = max(inc,exc);
    dp[curr][prev+1] = ans;
    return dp[curr][prev+1];
}

int solveTab(int arr[],int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int curr = n-1 ; curr >= 0 ;curr--)
    {
        
        for(int prev = curr-1; prev >= -1 ; prev--)
        {
            int inc = 0;
            if(prev == -1 || arr[curr] > arr[prev])
            {
                inc =1+dp[curr+1][curr+1];
            }
            int exc = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(inc,exc);
        }
    }
    return dp[0][0];
    
}

int solveTabSO(int arr[],int n)
{
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);
    

    for(int curr_i = n-1 ; curr_i >= 0 ;curr_i--)
    {
        
        for(int prev_i = curr_i-1; prev_i >= -1 ; prev_i--)
        {
            int inc = 0;
            if(prev_i == -1 || arr[curr_i] > arr[prev_i])
            {
                inc =1+next[curr_i+1];
            }
            int exc = 0 + next[prev_i+1];
            curr[prev_i+1] = max(inc,exc);
        }
        next = curr;
    }
    return next[0];
    
}

//by binary search
int solveBin(int arr[],int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1 ;i < n ; i++)
    {
        if(arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else{
            int idex = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[idex] = arr[i];
        }
    }
    return  ans.size();
}



int main()
{
    int arr[8]={10,9,2,5,3,7,101,18};
    int n = 8;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<solveBin(arr,n)<<endl;
}