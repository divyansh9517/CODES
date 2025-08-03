#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<int> &arr)
{
    int gondola = 0;
    int i = 0 ;
    int j = n -1;
    sort(arr.begin(),arr.end());
    while(i<=j)
    {
        if(arr[i] + arr[j] <= k)
        {
            i++;
        }
        j--;
        gondola++;
    }
    return gondola;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    cout<<solve(n,k,arr);
}