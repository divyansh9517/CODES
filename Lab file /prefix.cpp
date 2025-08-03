#include<bits/stdc++.h>
using namespace std;

int sum(int l ,int r,vector<int> &arr)
{
    int sum = 0;
    for(int i = l ; i < r ; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    vector<int> arr = {1,2,3,6,4,9};
    int l = 1;
    int r = 5;
    cout<<sum(l,r,arr);
}