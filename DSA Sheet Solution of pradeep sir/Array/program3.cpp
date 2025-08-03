#include<bits/stdc++.h>

using namespace std;

void rearrangeArray(vector<int>& nums) {
    vector<int> neg;
    vector<int> pos;
    for(int  i = 0 ; i < nums.size() ; i++)
    {
        if(nums[i] >= 0)
        {
            pos.push_back(nums[i]);
        }
        else{
            neg.push_back(nums[i]);
        }
    }

    vector<int> ans(nums.size());
    int negIdx = 0;
    int posIdx = 0;

    for(int i = 0 ;i < nums.size() ; i++)
    {
        if(i % 2 == 0)
        {
            ans[i] = pos[posIdx++];
        }
        else{
            ans[i] = neg[negIdx++];
        }
    }
    for(int i = 0 ; i< ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<int> nums = {3,1,23,-1,2,-2,-3,-4};
    rearrangeArray(nums);
}