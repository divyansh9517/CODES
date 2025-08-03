#include<bits/stdc++.h>
using namespace std;

void solution1(vector<int> &arr)
{
    int maxi = arr[0];
    int minimum = arr[0];
    int n = arr.size();

    for(int i = 0 ; i < n ; i++)
    {
        maxi = max(maxi,arr[i]);
        minimum = min(minimum,arr[i]);
    }
    cout<<"Minimum element : - "<<minimum<<endl;
    cout<<"Maximum element : - "<<maxi<<endl;
}
void solution2(vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    cout<<"Maximum element in array : - "<<arr[0]<<endl;
    cout<<"Minimum element of array : - "<<arr[arr.size()-1]<<endl;
}

int main()
{
    int n ;
    cout<<"What is the size of array: - "<<endl;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    solution1(arr);
    solution2(arr);
    return 0;
}