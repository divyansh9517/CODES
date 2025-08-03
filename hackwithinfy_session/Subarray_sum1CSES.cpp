#include<bits/stdc++.h>
using namespace std;

int solve(int n , int x, vector<long long>&arr)
{
    int left = 0; 
    int right = -1;
    long long sum = 0;
    long long cnt = 0;
    while(right < n)
    {
        while(right < n && sum < x)
        {
            right = right+1;
            sum += arr[right];
        }

        while(left <= right && sum > x)
        {
            sum -= arr[left];
            left++;
        }

        if(sum == x)
        {
            cnt++;
            sum -= arr[left];
            left++;
        }
    }
    return cnt;
}
int main(){
    int n;
    long long x ;
    cin >> n >> x;
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    long long ans = solve(n,x,arr);
    cout<<ans<<endl;
    return 0 ;
}