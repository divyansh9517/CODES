#include<bits/stdc++.h>
using namespace std;

void next_greater_element(vector<int> &arr1,vector<int> &arr2)
{
    stack<int> st;
    unordered_map<int,int> mpp;
    int n = arr1.size();
    for(int i = n -1; i>=0; i--)
    {
        while(!st.empty() && st.top() <= arr1[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            mpp[arr1[i]] = st.top();
        }
        else{
            mpp[arr1[i]] = -1;
        }
        st.push(arr1[i]);
    }

    vector<int> ans;
    for(auto i : arr2)
    {
        ans.push_back(mpp[i]);
    }

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<int> arr1 = {1,3,4,2};
    vector<int> arr2 = {4,1,2};
    next_greater_element(arr1,arr2);
}