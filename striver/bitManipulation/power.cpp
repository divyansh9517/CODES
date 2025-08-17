#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int solve(int x,int n,int mod){
    long long ans = 1;
    while(n > 0){
        if(n &1){
            ans = (ans * x) %mod;
            n = n -1;
        }
        else{
            n = n>>1;
            x = (x * x)%mod;
        }

    }
    return ans;
}

int main(){
    int x = 3;
    int n = 9;
    int ans = solve(x,n,MOD);
    cout<<ans<<" ";
    return 0;
}