#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {20,15,26,2,6,96};
    int n = arr.size();
    // using map
    vector<int> temp = arr;
    sort(temp.begin(),temp.end());
    unordered_map<int,int> mp;
    int k = 1;
    for(int i = 0; i < n ; i++){
        if(mp[temp[i]] == 0)
        {
            mp[temp[i]] = k++;
        }
    }

    for(int i = 0 ;i < n ;i++){
        cout<<mp[arr[i]]<<" ";
    }
    return 0;
    // TC -> O(NlogN)
    // SC -> O(N)
}
