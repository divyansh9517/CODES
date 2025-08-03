#include<bits/stdc++.h>

using namespace std;

int solve(int l,int r)
{
    int sum = 0;
    for(int i = l ; i<=r ;i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    int l = 2 ;
    int r = 5;
    int ans = solve(l,r);
    cout<<ans;
    return 0;
}