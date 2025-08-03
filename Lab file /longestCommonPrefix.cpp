#include<bits/stdc++.h>
using namespace std;

string solve(vector<string> &str)
{
    int n = str.size();
    string ans = "";
    sort(str.begin(),str.end());

    string first = str[0],last = str[n-1];
    for(int i = 0 ; i < min(first.size(),last.size());i++)
    {
        if(first[i] != last[i])
        {
            return ans;
        }
        ans +=first[i];
    }
    return ans;
}

int main(){
    vector<string> str = {"flower","floor","flat","flight"};
    cout<<solve(str);
}