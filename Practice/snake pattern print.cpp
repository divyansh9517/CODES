#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0 ; j < arr.size();j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int j = arr.size() -1 ; j >= 0 ;j--)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}