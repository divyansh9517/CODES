#include<bits/stdc++.h>
using namespace std;

string solve(int n , int sum)
{
    string res = "";
    for(int i = 0 ;i < n ; i++)
    {
        int digit = min(9,sum);
        res += to_string(digit);
        sum -= digit;
    }
    return res;
}

int main(){
    int n = 3 ; 
    int sum = 20;
    cout<<solve(n,sum)<<endl;
    return 0;
}