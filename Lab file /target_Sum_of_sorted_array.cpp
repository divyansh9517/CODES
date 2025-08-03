#include<bits/stdc++.h>
using namespace std;

vector<int> target_pair(vector<int>&arr,int target)
{
    int left = 0;
    int right = arr.size()-1;
    while(left < arr.size() && right >= 0)
    {
        if(arr[left]+arr[right] == target)
        {
            return {arr[left],arr[right]};
        }
        if(arr[left]+arr[right] > target)
        {
            right--;
        }
        else{
            left++;
        }
    }
    return {-1,-1};
}

int main()
{
    vector<int> arr= {1,2,4,7,11,15};
    vector<int> ans = target_pair(arr,15);
    for(int i = 0 ; i <  ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}