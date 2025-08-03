#include<bits/stdc++.h>
using namespace std;

int cntSet_Bits(int n)
{
    vector<int> ans;
    int i = 0;
    while(n != 0)
    {
        int sum = n%2;
        
        n = n/2;
        ans.push_back(sum) ;
    }

    int cnt = 0;
    for(int i = 0 ; i < ans.size() ; i++)
    {
        if(ans[i] == 1)
        {
            cnt++;
        }
    }
    return cnt;
}


int main(){
    int n = 8;
    cout<<cntSet_Bits(n);
    return 0;
}