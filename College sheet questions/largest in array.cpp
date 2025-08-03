#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {15, 22, 3, 8, 19};
    int maxi = arr[0];

    for(int i = 0 ; i<arr.size() ; i++)
    {
        if(maxi < arr[i])
        {
            maxi = arr[i];
        }
    }
    cout<<maxi;
}