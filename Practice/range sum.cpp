#include<bits/stdc++.h>
using namespace std;
int rangSum(int left,int right , vector<int>& nums)
{
    int prfix=0;
    for(int i = left ; i <= right; i++)
    {
        prfix+=nums[i];
    }
    return prfix;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int left,right;
    cin>>left>>right;
    cout<<rangSum(left,right,arr);
}