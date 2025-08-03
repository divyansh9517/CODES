#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;

    unordered_map<int,int> mapp;

    for(int i = 0; i< arr.size() ; i++)
    {
        int rem = target - arr[i];

        if(mapp.find(rem) != mapp.end())
        {
            cout<<mapp[rem]<<" "<<i;
        }
        mapp[arr[i]] = i;

    }
    return 0;
}