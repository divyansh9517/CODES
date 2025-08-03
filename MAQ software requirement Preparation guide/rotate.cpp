#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int k)
{
    int n = arr.size();
    vector<int> temp(n);
    for(int i = 0 ; i < n ; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    for(int i = 0 ;i < n ; i++){
        cout<<temp[i]<<" ";
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    solve(arr,1);
}