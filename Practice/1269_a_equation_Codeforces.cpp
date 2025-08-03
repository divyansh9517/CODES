#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a = 9*n;
    long long b= 8*n;
    long long ans = a - b;
    if(ans == n)
    {
        cout<<a<<" "<<b;
    }
    return 0;
    
}