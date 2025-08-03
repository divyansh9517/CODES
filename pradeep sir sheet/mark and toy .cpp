#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int k)
{
    sort(arr.begin(),arr.end());
    int sum = 0;
    int cnt = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        sum += arr[i];
        if(sum <= k)
        {
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int k = 7;
    cout<<solve(arr,k)<<" ";
}