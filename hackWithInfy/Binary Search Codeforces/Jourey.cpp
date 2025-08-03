#include<bits/stdc++.h>
using namespace std;

long long solve(long long day, long long a,long long  b, long long c)
{
    long cycle = day/3;
    long rem = day%3;
    long long dist = cycle*(a+b+c);
    if(rem == 1) dist += a;
    else if(rem == 2) dist += a+b;

    return dist;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n,a,b,c;
        cin>>n>>a>>b>>c;

        long  left = 1 ; 
        long right = n;
        long ans = n;

        while(left <= right)
        {
            long mid = left + (right-left)/2;
            if(solve(mid,a,b,c) >= n)
            {
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        cout<<ans<<'\n';

    }
    return 0;
}
