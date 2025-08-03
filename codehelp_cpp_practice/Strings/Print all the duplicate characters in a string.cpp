#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
    map<char,int> mpp;
    sort(s.begin(),s.end());
    for(auto i : s)
    {
        mpp[i]++;
    }

    for(auto i : mpp)
    {
        if(i.second >= 2)
        {
            cout<<i.first<<" - >  "<<i.second<<endl;
        }
    }
}

int main(){
    string s = "geeksforgeeks";
    solve(s);
}