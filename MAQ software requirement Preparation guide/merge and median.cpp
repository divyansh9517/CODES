#include<bits/stdc++.h>

using namespace std;

void merge_and_median(vector<int> & nums1,vector<int> & nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> arr;
    arr.resize(n + m); // Important: allocate space

    int i = 0;
    int j = 0;
    int idx = 0;

    while(i < n && j < m)
    {
        if(nums1[i] < nums2[j])
        {
            arr[idx++] = nums1[i++];
        }
        else
        {
            arr[idx++] = nums2[j++];
        }
    }

    while(i < n)
    {
        arr[idx++] = nums1[i++];
    }

    while(j < m)
    {
        arr[idx++] = nums2[j++];
    }

    if(arr.size() %2 == 0)
    {
        int ans = (arr[n/2] + arr[n+1/2])/2;
        cout<<ans;
    }
    else{
        cout<<arr[n/2];
    }
     
}

int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    merge_and_median(nums1,nums2);

}