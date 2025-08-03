#include<bits/stdc++.h>
using namespace std;

void moveAllZeroAtEnd(vector<int>& arr)
{
    int index = 0;
    for(int i =0 ; i < arr.size() ; i++)
    {
        if(arr[i] != 0)
        {
            arr[index++] = arr[i];
        }
    }
    for(int i = index ; i < arr.size() ; i++)
    {
        arr[i] = 0;
    }
    for(int i = 0 ;i < arr.size() ;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    vector<int> arr(5);
    for(int i = 0 ; i < 5 ;i++)
    {
        cin>>arr[i];
    }
    moveAllZeroAtEnd(arr);
    return 0;
}