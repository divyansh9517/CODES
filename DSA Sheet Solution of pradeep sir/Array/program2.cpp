#include<bits/stdc++.h>
using namespace std;

void sortedSquares(vector<int>& nums) {
    vector<int> temp(nums.size()) ;
    for(int i = 0; i < nums.size() ; i++)
    {
        temp[i] = nums[i]*nums[i];
    }

    sort(temp.begin(),temp.end());
    nums = temp;

}

int main(){
    vector<int> nums={-4,-1,0,2,3,10};
    sortedSquares(nums);

    for(int i = 0 ; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}
