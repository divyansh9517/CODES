#include<bits/stdc++.h>
using namespace std;

int elementBYmap(vector<int> &arr)
{
    unordered_map<int,int> mpp;
    for(int num : arr)
    {
        mpp[num]++;
    }

    for(auto i:mpp)
    {
        if(i.second > arr.size()/2)
        {
            return i.first;
        }
    }
    return -1;
}
int withoutMap(vector<int> &arr)
{
    int cnt = 0;
    int candidate = -1;
    for(int i = 0 ; i < arr.size();i++)
    {
        if(cnt == 0)
        {
            cnt  = 1;
            candidate = arr[i];
        }
        cnt += candidate == arr[i] ?-1 :1;
    }
    return candidate;
}
int main(){
    vector<int> arr = {1,2,3,3,3,4,3};
    cout<<withoutMap(arr);
}