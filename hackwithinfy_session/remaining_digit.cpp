#include<bits/stdc++.h>

using namespace std;
int Digits(int n)
{
    int largest = 0;
    

    while (n) {
        int r = n % 10;

       
        largest = max(r, largest);

       

        n = n / 10;
    }
    return largest;
}

int solve(int n,vector<int>&dp)
{
    if(n == 0)
    {
        return 0;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    int maxD = Digits(n);

    dp[n]= 1 + solve(n - maxD,dp);
    
    return dp[n];
}

int main()
{
    int n;
    
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<solve(n,dp);
    
    
}