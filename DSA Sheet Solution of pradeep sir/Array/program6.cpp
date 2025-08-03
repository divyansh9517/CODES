#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& nums,int target)
{
    int start = 0;
    int end = nums.size() -1;

    while(start <= end)
    {
        int mid = start + (end -start)/2;
        if(nums[mid] == target)
        {
            return mid;
        }

        if(nums[mid] > target)
        {
            end = mid - 1;
        }
        else{
            start = mid +1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int target = 5;
    int ans = binarySearch(nums,target);
    cout<<ans;
    return 0;
}