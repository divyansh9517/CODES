#include<bits/stdc++.h>
using namespace std;

bool isSubarry(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    if(sum % 2 == 0)
    {
        return true;
    }
    return false;
}
bool isSolve(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    
    int left = 0;
    for(int i = 0 ; i < n ; i++)
    {
        left += arr[i];
        if(left*2 == sum)
        {
            return true;
        }
    }
    return false;
}
int findSplitPoint(vector<int>& arr,int n)
{
    int left = 0;
    for(int i = 0 ; i < n ; i++)
    {
        left += arr[i];
    }
    int right = 0;
    for(int i = n-1 ; i >= 0 ; i--)
    {
        right += arr[i];
        left -= arr[i];
        if(right == left)
        {
            return i;
        }
    }
    return -1;
}

void solve(vector<int> &arr,int n)
{
    int split = findSplitPoint(arr,n);
    if(split == -1 || split == n)
    {
        cout<<"Not Possible";
        return ;
    }
    for(int  i = 0 ; i < n ; i++)
    {
        if(split == i)
        {
            cout<<endl;
        }
        cout<<arr[i]<<" ";
    }

}

int main(){
    vector<int> arr = {1,2,3,4,5,5};
    int n = arr.size();
    solve(arr,n);
    // if(isSolve(arr))
    // {
    //     cout<<"yes";
    // }
    // else{
    //     cout<<"NO";
    // }
    return 0;
}