#include<bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>> & arr)
{
    vector<int> ans;
    int row = arr.size();
    int col = arr[0].size();
    for(int i = 0 ; i < row ;i++)
    {
        for(int j = 0 ; j< col ; j++)
        {
            ans.push_back(arr[i][j]);
        }
    }

    sort(ans.begin(),ans.end());

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<vector<int>> arr= {{1,2,3},{1,2,3},{4,5,6}};
    merge(arr);
}