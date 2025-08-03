#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ;i++)
    {
        cin>>arr[i];
    }

    int maxHeight = -1e9, minHeight = 1e9;
    int minIdx = 0, maxIdx = 0;

    // finding the maximum element idx

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i]>maxHeight)
        {
            maxHeight = arr[i];
            maxIdx = i;
        }
    }

    //finding the minimum element
    for(int i = n-1; i>=0 ; i--)
    {
        if(arr[i]<minHeight)
        {
            minHeight =  arr[i];
            minIdx = i;
        }
    }
    int res = maxIdx + (n-1 -minIdx);
    if(minIdx < maxIdx){
        res--;
    }
    cout<<res;
}