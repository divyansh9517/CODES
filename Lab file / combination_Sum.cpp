#include<bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int> &arr, int target,vector<vector<int>> &ans,vector<int> &ds)
{
    if(idx == arr.size())
    {
        if(target == 0)
        {
            ans.push_back(vector<int>(ds));
        }
        return ;
    }
    if(arr[idx] <= target)
    {
        ds.push_back(arr[idx]);
        solve(idx,arr,target-arr[idx],ans,ds);
        ds.pop_back();
    }
    solve(idx+1,arr,target,ans,ds);
}


void combination(vector<int> arr,int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0,arr,target,ans,ds);
    for(int i = 0 ;i < ans.size();i++)
    {
        for(int j = 0; j < ans.size()+1 ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    vector<int> arr= {2,3,6,7};
    int target = 7;

    combination(arr,target);
}