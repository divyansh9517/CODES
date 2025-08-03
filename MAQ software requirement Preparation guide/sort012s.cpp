#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr)
{

    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(arr[i] == 0)
        {
            c0++;
        }
        if(arr[i] == 1)
        {
            c1++;
        }
        if(arr[i] == 2)
        {
            c2++;
        }
    }
    vector<int> ans(arr.size());
    for(int i = 0 ; i < c0 ; i++)
    {
        ans[i] = 0;
    }

    for(int i = c0 ;i <c0+c1 ; i++)
    {
        ans[i] = 1;
    }

    for(int i = c0+c1 ; i< c0+c1+c2 ;i++)
    {
        ans[i] = 2;
    }

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }

}
int main(){
    vector<int> arr = {1,2,1,2,1,1,1,0,0,0,1,2};
    solve(arr);
}