#include<bits/stdc++.h>
using namespace std;

vector<int> sortColors(vector<int>& arr)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0 ;i < arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            cnt0++;
        }

        else if(arr[i] == 1)
        {
            cnt1++;
        }
        else if(arr[i] == 2)
        {
            cnt2++;
        }
    }

    vector<int> ans(arr.size());
    for(int i = 0 ; i < cnt0; i++)
    {
        arr[i] = 0;
    }

    for(int i = cnt0 ; i < cnt0+cnt1;i++)
    {
        arr[i] = 1;
    }

    for(int i =cnt0+cnt1 ; i<cnt0+cnt1+cnt2; i++)
    {
        arr[i] = 2;
    }


    for(int i = 0 ; i < ans.size() ;i++)
    {
        cout<<arr[i];
    }

    cout<<endl;
    return arr;
}

int main(){
    vector<int> arr = {1,2,2,1,1,2,0,0,0,0,1,2,2,0};
    //vector<int> ans(arr.size(),0);
    sortColors(arr);
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout<<arr[i]<<" ";
    }
}