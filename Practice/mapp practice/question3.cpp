#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums)
{
    unordered_map<int,int> mapp;
    int sum = 0 ;
    int maxi = 0;
    mapp[0] = -1;

    for(int i = 0 ; i<nums.size() ; i++)
    {
        if(nums[i] == 0)
        {
            sum = sum-1;
        }

        if(nums[i] == 1)
        {
            sum = sum+1;
        }

        if(mapp.find(sum) != mapp.end()){
            maxi = max(maxi , i - mapp[sum]);
        }
        else{
            mapp[sum] = i;
        }

        
    }
    return maxi;

}

int main()
{
    vector<int> arr = {0,1,0};
    cout<<solve(arr);
    return 0;
}