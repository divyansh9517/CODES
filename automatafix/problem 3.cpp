#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr,int size)
{
    vector<int> left(size,1) ,right(size,1);
    vector<int> ans(arr.size());

    for(int i = 1 ; i < size ;i++)
    {
        left[i] = left[i-1]*arr[i-1];
    }

    for(int i = size-2 ; i >= 0; i-- )
    {
        right[i] = right[i+1] * arr[i+1];
    }


    for(int i = 0; i < size ;i++)
    {
        ans[i] = left[i] * right[i];
    }

    for(int i =0 ; i< size ; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main()
{
    vector<int> arr={1,2,3,4};
    solve(arr,4);
    return 0;
}