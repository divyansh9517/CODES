#include<bits/stdc++.h>
using namespace std;

bool solve(int i , int target , vector<int>&arr,vector<vector<int>> &dp)
{
    if(target == 0)
    {
        return true;
    }
    if(i == 0)
    {
        return arr[i] == target;
    }
    if(dp[i][target] != -1)
    {
        return dp[i][target];
    }

    bool notTaken = solve(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i] <= target)
    {
        taken = solve(i-1,target- arr[i],arr,dp);
    }
    return dp[i][target] = taken||notTaken;
}
int main(){
    vector<int> arr = {2,1,3,4,6};
    int target = 10;
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    bool anss = solve(n-1,target,arr,dp);

    if(anss)
    {
        cout<<"Yes there exist an subset";
    }
    else{
        cout<<"No there is no subset exist";
    }
}