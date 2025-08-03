#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int> &l ,vector<int>& r)
{
    return l[0]>r[0];
}
int maximumLuck(vector<vector<int>> &arr,int k)
{
    int ans = 0;
    int im = 0;
    sort(arr.begin(),arr.end(),comp);
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(im < k || arr[i][1]==0)
        {
            ans+=arr[i][0];
        }
        else{
            ans -= arr[i][0];
        }
        if(arr[i][1] == 1)im++;
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {
        {5,1},
        {2,1},
        {1,1},
        {8,1},
        {10,0},
        {5,0}
    };
    int k= 3;
    cout<<maximumLuck(arr,k);
}