#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {2,5,3,6,0,8};
    int target =0;

    for(int i = 0  ;i < arr.size() ;i++)
    {
        if(arr[i] == target)
        {
            cout<<i<<" "; 
            break;
        }

    }
}