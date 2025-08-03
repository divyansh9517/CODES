#include<bits/stdc++.h>
using namespace std;

int loweBound(vector<int>& arr,int target)
{
    int start = 0;
    int end = arr.size();
    int ans =-1;
    while(start < end)
    {
        int mid = (end+start)/2;

        if(arr[mid] <= target)
        {
            ans = mid;
            start = mid+1;
            
        }
        else{
            end = mid -1;
            
        }
    }
    return ans ;
}

int upperBound(vector<int>& arr,int target)
{
    int start = 0;
    int end = arr.size();
    int ans =-1;
    while(start < end)
    {
        int mid = (end+start)/2;

        if(arr[mid] >= target)
        {
            ans = mid;
            end = mid -1;
            
            
        }
        else{
            
            start = mid+1;
        }
    }
    return ans ;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    int lb = loweBound(arr,5);
    int rb = upperBound(arr,5);
    cout<<arr[lb]<<endl;
    cout<<arr[rb]<<endl;
    
}