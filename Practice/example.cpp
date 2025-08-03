#include<bits/stdc++.h>

using namespace std;
int solve(vector<int> arr)
{
    int maxi = 0;
    for(int i = 1 ; i < arr.size() ; i++)
    {
        int ans = arr[i-1]^arr[i];

        maxi = max(maxi,ans);
    }
    return maxi;
}
int main(){
    vector<int> arr = {1,2,3,1,3,4,5};
    cout<<solve(arr);
}