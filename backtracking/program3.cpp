#include<bits/stdc++.h>
using namespace std;

void permute(vector<int> & arr,int l,int r)
{
    if(l == r)
    {
        for (int i = 0; i <= r; i++)  // Print the array
        {
            cout << arr[i] << " ";
        }
        cout << endl; 
    }

    for(int i = l ; i<= r; i++)
    {
        swap(arr[l],arr[i]);
        permute(arr,l+1,r);
        swap(arr[l],arr[i]);
    }
}


int main()
{
    vector<int> arr= {1,2,3};
    int l = 0; 
    int r = arr.size()-1;
    permute(arr,l,r);
}