#include<bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
    vector<int> temp(nums.size());
    int idx = 0;
    int cnt= 0;
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[i] != 0)
        {
            temp[idx] = nums[i];
            idx++;
        }
        else{
            cnt++;
        }
    }
    while(cnt != 0)
    {
        temp[idx++]=0;
        cnt--;
    }
    nums = temp;
}

int main()
{
    vector<int> nums= {1,0,2,3,0,4,5,6,0};

    moveZeroes(nums);
    for(int i = 0 ;i < nums.size() ; i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}