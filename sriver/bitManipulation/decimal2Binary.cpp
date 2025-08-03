#include<bits/stdc++.h>
using namespace std;

string solve(int n)
{

    string res= "";
    if (n == 0) return "0";
    while(n>0){
        if(n%2 == 1)res +='1';
        else res += '0';
        n = n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int x = 13;
    string ans = solve(x);
    cout<<ans<<" ";
    return 0;
}