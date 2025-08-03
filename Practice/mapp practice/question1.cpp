#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> arr1,vector<int> arr2)
{
    set<int> a1;
    set<int> a2;

    for(int i = 0; i < arr1.size();i++)
    {
        a1.insert(arr1[i]);
    }


    for(int i = 0 ; i < arr2.size() ;i++)
    {
        a2.insert(arr2[i]);
    }


    vector<int> a(a1.begin(),a1.end());
    vector<int> b(a2.begin(),a2.end());

    unordered_map<int,int> mapp;

    for(int i = 0 ; i < a.size() ; i++)
    {
        mapp[a[i]]++;
    }

    for(int i  = 0; i < b.size();i++)
    {
        mapp[b[i]]++;
    }

    vector<int> ans;
    for(auto n : mapp)
    {
        if(n.second == 2)
        {
            ans.push_back(n.first);
        }
    }

    for(int i = 0 ; i <ans.size() ;i++)
    {
        cout<<ans[i]<<" ";
    }


    
}

int main()
{
    vector<int> arr1= {4,9,5};
    vector<int> arr2= {9,4,9,8,4};

    solve(arr1,arr2);
    return 0;
}