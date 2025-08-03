#include<bits/stdc++.h>
using namespace std;


int maxSum(vector<int>& arr)
{
    int sum = 0; 
    int max_ans = INT_MIN;

    for(int i = 0 ; i < arr.size() ; i++)
    {
        sum +=arr[i];
        max_ans = max(max_ans,sum);

        if(sum < 0)
        {
            sum = 0;
        }
    }
    return max_ans;
}

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSum(arr);
    cout<<ans;
    return 0;
}