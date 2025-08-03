#include<bits/stdc++.h>
using namespace std;

void sorti(vector<int> arr)
{
    int count0 = 0 ;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0 ; i < arr.size();i++)
    {
        if(arr[i] == 0)
        {
            count0++;
        }
        if(arr[i] == 1)
        {
            count1++;
        }
        if(arr[i] == 2)
        {
            count2++;
        }
    }

    for(int i = 0 ; i < count0 ; i++)
    {
        arr[i] = 0;
    }
    for(int i = count1 ; i < count0+count1 ; i ++)
    {
        arr[i] = 1;
    }
    for(int i = count1+count2 ; i < count0+count1+count2 ;i++)
    {
        arr[i] = 2;
    }

    for(int i = 0 ;  i < arr.size() ; i++)
    {
        cout<<arr[i]<<",";
    }
}
int main(){
    vector<int>arr(6);
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cin>>arr[i];
    }
    sorti(arr);
    return 0;
}