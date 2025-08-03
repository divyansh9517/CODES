#include<bits/stdc++.h>
using namespace std;
int trappingWater(vector<int> &arr)
{
    int n = arr.size();
    if(n == 0)
    {
        return 0;
    }
    vector<int> lb(n);
    vector<int> rb(n);

    lb[0] = arr[0];
    for(int i = 1; i < n ; i++)
    {
        lb[i] = max(lb[i-1],arr[i]);
    }

    rb[n-1] = arr[n-1];
    for(int i = n-2 ; i>=0 ; i--)
    {
        rb[i] = max(rb[i+1],arr[i]);
    }

    int res = 0;
    for(int i = 1 ; i < n-2 ; i++)
    {
        res += min(lb[i],rb[i])-arr[i];
    }
    return res;
}

int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappingWater(arr);
}