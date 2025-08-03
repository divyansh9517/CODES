#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll solve(int n, vector<ll>& arr)
{
    unordered_map<ll ,ll> mpp;
    mpp[0] = 1;
    ll cnt = 0;
    ll sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum = (sum + arr[i]) % n;
        if(sum < 0) sum += n;

        cnt += mpp[sum];
        mpp[sum]++;
    }
    return cnt;
}

int main()
{
    int n; 
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }
    ll ans = solve(n, arr);
    cout << ans << endl;
    return 0;
}
