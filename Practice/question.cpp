#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr)
{
    int n = arr.size();

    if(n%2 == 0)
    {
        for(int i = 0; i < n ;i++)
        {
            arr[i] = 0;
        }

        for(int i = 0 ; i < n ; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i = 0 ; i < n ;i++)
        {
            arr[i] = 1;
        }
        for(int i = 0 ; i < n ; i++)
        {
            cout<<arr[i];
        }
    }
}

int main(){

    vector<int> arr= {1,2,3,4,5,60};
    solve(arr);
}