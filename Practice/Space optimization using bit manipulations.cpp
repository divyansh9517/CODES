#include<bits/stdc++.h>

using namespace std;

void solve(int a,int b)
{
    map<int,int> mapp;

    for(int i = a ; i <= b ; i++)
    {
        if(i%2== 0 || i % 5 ==0)
        {
            mapp[i] = 1;
        }
        else{
            mapp[i] = 0;
        }
    }

    for(auto i : mapp)
    {
        if(i.second == 1)
        {
            cout<<i.first<<" ";
        }
    }
}

int main()
{
    int a = 2 ;
    int b = 10;

    solve(a,b);
    return 0;
}