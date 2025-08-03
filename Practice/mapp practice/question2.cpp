#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> arr,int k)
{
    unordered_map<int,int> mapp;

    int sum = 0; 
    int res = 0;
    mapp[0] = 1;
    for(int num : arr)
    {
        sum += num;
        int mod = (sum%k+k)%k;
        res += mapp[mod];

        mapp[mod]++;
        
    }
    return res;
}

int main(){
    vector<int> arr = {4,5,0,-2,-3,1};
    int k = 5;

    int ans = solve(arr,k);
    cout<<ans<<" ";
}