#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& arr,int k)
{
    unordered_map<int,int> mpp;
    int n = arr.size();

    int prefix = 0;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        prefix += arr[i];

        if(prefix == k)
        {
            cnt++;
        }

        if(mpp.find(prefix - k) != mpp.end())
        {
            cnt += mpp[prefix - k];
        }
        mpp[prefix]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr= {1,2,3};
    int k = 3;
    cout<<subarraySum(arr,k);
    return 0;
}