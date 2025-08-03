#include<bits/stdc++.h>
using namespace std;
int solve(int n)
{
    
   // vector<int> dp(n+1);
    int prev = 0 ;
    int prev2 = 1;
    int curr = 0;


    for(int i = 2 ; i <= n ; i++)
    {
        curr = prev + prev2;

        prev = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main(){
    int n ;
    cin>>n;
    //vector<int>dp(n+1,-1);
    cout<<solve(n);
}