#include<bits/stdc++.h>
using namespace std;

int solve1(vector<int>& nums)
{
    int n = nums.size();
    int left = 0;
    int right = n;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] < 0)
        {
            left  = left+1;
        }
        else{
            right = mid;
        }
    }
    return left;
}
int solve2(vector<int>& nums)
{
    int n = nums.size();
    int left = 0;
    int right = n;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] <= 0)
        {
            left  = left+1;
        }
        else{
            right = mid;
        }
    }
    return n-left;
}
int main()
{
    vector<int> nums= {-3,-2,-1,0,0,1,2};
    int neg = solve1(nums);
    int pos = solve2(nums);

    cout<<max(neg,pos);
}