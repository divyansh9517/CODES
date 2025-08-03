#include<bits/stdc++.h>

#include<algorithm>
using namespace std;
// int countFreq(vector<int>& arr, int target) {
//     // code here
//     int *left = lower_bound(arr.begin(),arr.end(),target);
//     int *right = upper_bound(arr.begin(),arr.end(),target);
    
//     int leftans =  left - arr.begin();
//     int rightans = right - arr.begin();
    
//     int ans = rightans - leftans +1;
//     return ans;     
// }

int solveForLeft(vector<int>& nums, int target)
    {
        int start = 0; 
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid] == target)
            {
                ans = mid;
                end = mid - 1;
            }

            else if(target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid+1;
            }
        }

        return ans ;
    }

    int solveForRight(vector<int>& nums, int target)
    {
        int start = 0; 
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid] == target)
            {
                ans = mid;
                start = mid + 1;
            }

            else if(target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid+1;
            }
        }

        return ans ;
    }

int main(){
    vector<int> arr = {1,2,2,2,2,2,3,3,4,4,5};
    int target = 2;
    int ans1 = solveForLeft(arr,target);
    int ans2 = solveForRight(arr,target);
    cout<<ans2 - ans1 +1;
    return 0;
}