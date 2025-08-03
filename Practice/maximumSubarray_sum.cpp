#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & arr,int k)
{
    // int maxi = 0;
    // for(int i =0 ; i < arr.size()-k;i++)
    // {
    //     int sum = 0;
    //     for(int j = i ; j <= i+k ;j++)
    //     {
    //         sum += arr[j];
            
    //     }
    //     maxi = max(maxi ,sum);
 
    // }
    // return maxi;
    // int sum = 0; 
    // int  n = arr.size();
    // for(int i = 0 ; i<k  ; i++)
    // {
    //     sum += arr[i];
    // }
    // int maxSum = sum;
    // for(int i = k ; i < n ; i++)
    // {
    //     sum += arr[i] - arr[i-k];
    //     maxSum = max(maxSum,sum);
    // }
    // return maxSum;

    // sliding window
}

int main()
{
    vector<int> arr = {-1,2,3,-4,5};
    cout<<solve(arr,3);
    return 0;
}