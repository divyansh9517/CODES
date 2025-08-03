#include<bits/stdc++.h>

using namespace std;
int solve(int a,int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return 2;
    }

    return a*solve(a,b-1);
}

int main(){
    int a = 2 ;
    int b = 3;
    cout<<solve(a,b);
}