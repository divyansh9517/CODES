#include<bits/stdc++.h>
using namespace std;

void nextPermute(vector<int>& arr)
{
    int n = arr.size();
    int  i = n - 2;
    while(i >= 0 &&  arr[i] >= arr[i+1])
    {
        i--;
    }
    if(i >= 0)
    {
        int  j = n -1;
        while(j >= 0 && arr[i]>= arr[j])
        {
            j--;
        }
        swap(arr[i],arr[j]);
    }
    reverse(arr.begin()+i+1,arr.end());
}
int main(){
    vector<int> arr = {1,2,3};
    nextPermute(arr);
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout<<arr[i] <<" ";
    }
    return 0;
}