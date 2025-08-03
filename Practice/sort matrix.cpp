#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr = {{5,4,7},{1,3,8},{2,9,6}};
    vector<int> ans;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            ans.push_back(arr[i][j]);
        }
        

    }

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
    sort(ans.begin(),ans.end());

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }

}