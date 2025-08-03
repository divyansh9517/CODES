#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr)
{
    sort(arr.begin(),arr.end());
    int mini = INT_MAX;
    int diff = 0;
    for(int i = 1; i < arr.size() ;i++)
    {
        diff = abs(arr[i]- arr[i-1]);
        mini = min(mini,diff);
    }
    return mini;
}
int main(){
    vector<int> arr= {-3,71,68,17};
    cout<<solve(arr);
}